#include "dikinls_walk.hpp"


VectorXd DikinLSWalk::vect_pow(VectorXd& x, float alpha){
    for(int i = 0; i < x.rows(); i++){
        x(i) = pow(x(i), alpha);
    }
    return x;
}

VectorXd DikinLSWalk::gradient_descent(VectorXd& x, float adj, int sim, float gl){

    float q = 2 * (1 + log(A.rows()));
    float alpha = 1 - (2/q);

    VectorXd w_i = VectorXd::Ones(A.rows()); 
    MatrixXd slack = generate_slack(x).asDiagonal().toDenseMatrix();
    MatrixXd A_x = slack.colPivHouseholderQr().solve(A);

    VectorXd term2 = (0.5 - 1/q) * VectorXd::Ones(A.rows()); 

    while(sim--){
        MatrixXd W = vect_pow(w_i, alpha).asDiagonal().toDenseMatrix();

        VectorXd term1a = alpha * (vect_pow(w_i, alpha - 1));
        VectorXd term1b = (A_x * (A_x.transpose() * W * A_x).inverse() * A_x.transpose()).diagonal();

        VectorXd term1(A.rows());
        for(int i = 0; i < A.rows(); i++){
            term1(i) = term1a(i) * term1b(i);
        }

        
        VectorXd gradient = term1 - term2;
        if(gradient.norm() < gl){
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

VectorXd DikinLSWalk::generate_weight(VectorXd& x){
    VectorXd w = gradient_descent(x, step_size, max_iter, grad_lim);
    return w;
}

void DikinLSWalk::printType(){
    cout << "DikinLSWalk" << endl;
}