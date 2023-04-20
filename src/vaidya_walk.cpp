#include "vaidya_walk.hpp"

void VaidyaWalk::generate_weight(VectorXd& x){
    generate_dikin_hessian(x);
    MatrixXd hess_inv = dhess.inverse();
    MatrixXd slack_inv = slack.cwiseInverse().asDiagonal().toDenseMatrix();

    MatrixXd weights_mat = slack_inv * A * hess_inv * A.transpose() * slack_inv;

    VectorXd wi = weights_mat.diagonal();


    for(int i = 0; i < wi.rows(); i++){
        wi(i) = wi(i) + (double)(A.cols()/A.rows());
    }
    weights = wi.asDiagonal().toDenseMatrix();
}

void VaidyaWalk::generate_dikin_hessian(VectorXd& x){
    generate_slack(x);
    MatrixXd slack_inv = slack.cwiseInverse().asDiagonal().toDenseMatrix();
    dhess = A.transpose() * slack_inv * slack_inv * A;
}

void VaidyaWalk::printType(){
    cout << "Vaidya Walk" << endl;
}
