#include "random_walk.hpp"


void RandomWalk::initialize(MatrixXd A_p, VectorXd b_p, float r_p){
    A = A_p;
    b = b_p;
    r = r_p;
}

bool RandomWalk::accept_reject(VectorXd& z){
    return ((A * z) - b).maxCoeff() <= 0;
}

float RandomWalk::generate_gaussian(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    float r1 = dis(gen);
    float r2 = dis(gen);

    return sqrt(-2.0 * log(r1)) * cos((2.0 * M_PI * r2));
}

VectorXd RandomWalk::generate_gaussian_rv(int d){
    VectorXd v(d);
    for(int i = 0; i < d; i++){
        v(i) = generate_gaussian();
    }
    return v/v.norm();
}

MatrixXd RandomWalk::generate_complete_walk(int num_steps, VectorXd x){
    return MatrixXd::Zero(1,1);
}