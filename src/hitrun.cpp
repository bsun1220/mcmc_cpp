#include "hitrun.hpp"


double HitAndRun::distance(VectorXd& x, VectorXd&y){
    return (x - y).norm();
}

double HitAndRun::binary_search(VectorXd direction, VectorXd&x){

    VectorXd farth = x + r * direction;
    double dist = 0; 
    
    while(true){
        dist = distance(x, farth);
        farth = x +  2 * dist * direction; 
        if (!accept_reject(farth)){
            break; 
        }
    }
    VectorXd left = x;
    VectorXd right = farth;
    VectorXd mid = (x + farth)/2;

    while (distance(left, right) > err){
        mid = (left + right)/2; 
        if (accept_reject(mid)){
            left = mid; 
        } else {
            right = mid; 
        }
    }
    return distance(mid, x);
}

MatrixXd HitAndRun::generate_complete_walk(int num_steps, VectorXd x){
    int n = x.rows(); 
    MatrixXd results = MatrixXd::Zero(num_steps, n);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < num_steps; i++){
        VectorXd new_direct = generate_gaussian_rv(n);
        double pos_side = binary_search(new_direct, x);
        double neg_side = binary_search(new_direct * -1, x) * -1;
        float val = dis(gen);
        double random_point = val * (pos_side - neg_side) + neg_side; 
        x = random_point * new_direct + x; 
        results.row(i) = x; 
    }
    return results;
}