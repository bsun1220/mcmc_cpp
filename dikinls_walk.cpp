#include "dikinls_walk.hpp"


VectorXd DikinLSWalk::vect_pow(VectorXd x, float alpha){
    for(int i = 0; i < x.rows(); i++){
        x(i) = pow(x(i), alpha);
    }
    return x;
}

VectorXd DikinLSWalk::gradient_descent(VectorXd x, float adj, int sim){

    float q = 2 * (1 + log(A.rows()));
    float alpha = 1 - (2/q);

    VectorXd w_i = VectorXd::Ones(A.rows()); 
    MatrixXd slack_inv = generate_slack(x).asDiagonal().toDenseMatrix().inverse();
    MatrixXd A_x = slack_inv * A;

    while(sim--){
        VectorXd W = vect_pow(x, alpha).asDiagonal().toDenseMatrix();

        VectorXd term1a = alpha * (vect_pow(w_i, alpha - 1));
        VectorXd term1b = (A_x * A_x.transpose() * W * A_x * A_x.transpose()).diagonal();

        VectorXd term1(A.rows());
        for(int i = 0; i < A.rows(); i++){
            term1(i) = term1a(i) * term1b(i);
        }

        VectorXd term2 = (0.5 - 1/q) * VectorXd::Ones(A.rows()); 
        
        VectorXd gradient = term1 - term2;
        if(gradient.norm() < 0.01){
            break;
        }
        VectorXd proposal = w_i + adj * gradient;
        if(proposal.minCoeff() < 0){
            break; 
        }
        w_i = proposal;
    }

    return w_i;

    
}

VectorXd DikinLSWalk::generate_weight(VectorXd x){
    return gradient_descent(x, 0.1, 100);
}