#include "john_walk.hpp"

VectorXd JohnWalk::vect_pow(VectorXd x, float alpha){
    for(int i = 0; i < x.rows(); i++){
        x(i) = pow(x(i), alpha);
    }
    return x;
}

VectorXd JohnWalk::gradient_descent(VectorXd x, float adj, int sim){
    float alpha = 1 - 1/(log2(2 * A.rows() / A.cols()));
    float beta = A.cols() / (2 * A.rows());

    VectorXd w_i = VectorXd::Ones(A.rows()); 
    MatrixXd slack_inv = generate_slack(x).asDiagonal().toDenseMatrix().inverse();
    MatrixXd A_x = slack_inv * A;

    while(sim--){
        VectorXd W = vect_pow(x, alpha).asDiagonal().toDenseMatrix();

        VectorXd term1 = VectorXd::Ones(A.rows());
        VectorXd term2a = vect_pow(x, alpha - 1);
        VectorXd term2b = (A_x * A_x.transpose() * W * A_x * A_x.transpose()).diagonal();
        VectorXd term2 (A.rows());
        for(int i = 0; i < A.rows(); i++){
            term2(i) = term2a(i) * term2b(i);
        }
        VectorXd term3 = beta * w_i.inverse();
        
        VectorXd gradient = term1 - term2 - term3;
        if(gradient.norm() < 0.01){
            break;
        }
        w_i = w_i - adj * gradient;
    }

    return w_i;

    
}

VectorXd JohnWalk::generate_weight(VectorXd x){
    return gradient_descent(x, 0.1, 100);
}
