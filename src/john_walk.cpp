#include "john_walk.hpp"

VectorXd JohnWalk::vect_pow(VectorXd& x, float alpha){
    for(int i = 0; i < x.rows(); i++){
        x(i) = pow(x(i), alpha);
    }
    return x;
}

void JohnWalk::gradient_descent(VectorXd& x, float adj, int sim, float grad_lim){
    float alpha = 1 - 1/(log2(2 * A.rows() / A.cols()));
    float beta = (double)A.cols() / (2 * A.rows());

    VectorXd w_i = VectorXd::Ones(A.rows()); 
    generate_slack(x);
    MatrixXd slack_mat = slack.asDiagonal().toDenseMatrix();

    MatrixXd A_x = slack_mat.colPivHouseholderQr().solve(A);
    VectorXd term1 = VectorXd::Ones(A.rows());

    MatrixXd W(A.rows(), A.rows());
    VectorXd term2a (A.rows());
    VectorXd term2b (A.rows());
    VectorXd term2 (A.rows());
    VectorXd term3 (A.rows());
    VectorXd gradient (A.rows());

    while(sim--){
        W = vect_pow(w_i, alpha).asDiagonal().toDenseMatrix();

        term2a = vect_pow(w_i, alpha - 1);
        term2b = (A_x * (A_x.transpose() * W * A_x).inverse() * A_x.transpose()).diagonal();

        for(int i = 0; i < A.rows(); i++){
            term2(i) = term2a(i) * term2b(i);
        }
        term3 = beta * vect_pow(w_i, -1);
        
        gradient = term1 - term2 - term3;
        if(gradient.norm() < grad_lim){
            break;
        }
        w_i = w_i - adj * gradient;
    }

    weights = w_i.asDiagonal().toDenseMatrix();

    
}

void JohnWalk::generate_weight(VectorXd& x){
    gradient_descent(x, step_size, max_iter, grad_lim);
}

void JohnWalk::printType(){
    cout << "John Walk" << endl;
}