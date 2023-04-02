#include "john_walk.hpp"

VectorXd JohnWalk::vect_pow(VectorXd x, float alpha){
    for(int i = 0; i < x.rows(); i++){
        x(i) = pow(x(i), alpha);
    }
    return x;
}

VectorXd JohnWalk::gradient_descent(VectorXd x, float adj, int sim, float grad_lim){
    float alpha = 1 - 1/(log2(2 * A.rows() / A.cols()));
    float beta = (double)A.cols() / (2 * A.rows());

    VectorXd w_i = VectorXd::Ones(A.rows()); 
    MatrixXd slack_inv = generate_slack(x).asDiagonal().toDenseMatrix().inverse();
    MatrixXd A_x = slack_inv * A;

    while(sim--){
        MatrixXd W = vect_pow(w_i, alpha).asDiagonal().toDenseMatrix();
   
        VectorXd term1 = VectorXd::Ones(A.rows());

        VectorXd term2a = vect_pow(w_i, alpha - 1);
    
        VectorXd term2b = (A_x * (A_x.transpose() * W * A_x).inverse() * A_x.transpose()).diagonal();
    

        VectorXd term2 (A.rows());
        for(int i = 0; i < A.rows(); i++){
            term2(i) = term2a(i) * term2b(i);
        }
        VectorXd term3 = beta * vect_pow(w_i, -1);
        
        VectorXd gradient = term1 - term2 - term3;
        if(gradient.norm() < grad_lim){
            break;
        }
        w_i = w_i - adj * gradient;
    }

    return w_i;

    
}

VectorXd JohnWalk::generate_weight(VectorXd x){
    VectorXd w = gradient_descent(x, step_size, max_iter, grad_lim);
    return w;
}

void JohnWalk::printType(){
    cout << "John Walk" << endl;
}