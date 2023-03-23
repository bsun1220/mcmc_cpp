#include "vaidya_walk.hpp"

VectorXd VaidyaWalk::generate_weight(VectorXd x){
    MatrixXd hess = generate_dikin_hessian(x).inverse();
    MatrixXd slack_inv = BarrierWalk::generate_slack(x).asDiagonal().toDenseMatrix().inverse();

    MatrixXd weights_mat = slack_inv * A * hess * A.transpose() * slack_inv;

    VectorXd weights = weights_mat.diagonal();


    for(int i = 0; i < weights.rows(); i++){
        weights(i) = weights(i) + (double)(A.cols()/A.rows());
    }
    return weights;
}

MatrixXd VaidyaWalk::generate_dikin_hessian(VectorXd x){
    MatrixXd slack_inv = generate_slack(x).asDiagonal().toDenseMatrix().inverse();
    return A.transpose() * slack_inv * slack_inv * A;
}

void VaidyaWalk::printType(){
    cout << "Vaidya Walk" << endl;
}
