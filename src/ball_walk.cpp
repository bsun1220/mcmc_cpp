#include "ball_walk.hpp"


MatrixXd BallWalk::generate_complete_walk(int num_steps, VectorXd x){
    int n = x.rows(); 
    MatrixXd results = MatrixXd::Zero(num_steps, n);
    for (int i = 0; i < num_steps; i++){
        VectorXd new_x = generate_gaussian_rv(n) * r + x;
        if (accept_reject(new_x)){
            x = new_x;
        }
        results.row(i) = x; 
    }
    return results;
}