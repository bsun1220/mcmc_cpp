
#include "barrier_walk.hpp"

void BarrierWalk::set_ts(float a){
    term_sample = a; 
}

void BarrierWalk::set_td(float b){
    term_density = b; 
}

bool BarrierWalk::accept_reject(VectorXd z){
    return ((A * z) - b).maxCoeff() <= 0;
}

float BarrierWalk::generate_gaussian(){
    float r1 = (float)rand()/RAND_MAX;
    float r2 = (float)rand()/RAND_MAX;
    return sqrt(-2.0 * log(r1)) * cos((2.0 * M_PI * r2));
}

VectorXd BarrierWalk::generate_gaussian_rv(int d){
    VectorXd v(d);
    for(int i = 0; i < d; i++){
        v(i) = generate_gaussian();
    }
    return v;
}

VectorXd BarrierWalk::generate_slack(VectorXd x){
    return (b - (A * x));
}

float BarrierWalk::local_norm(VectorXd v, MatrixXd m){
    return ((v.transpose() * m) * v)(0);
}

VectorXd BarrierWalk::generate_weight(VectorXd x){
    int d = b.rows();
    return VectorXd::Ones(d);
}

MatrixXd BarrierWalk::generate_hessian(VectorXd x){
    MatrixXd weights = generate_weight(x).asDiagonal().toDenseMatrix();
    MatrixXd slack_inv = generate_slack(x).asDiagonal().toDenseMatrix().inverse();

    return A.transpose() * slack_inv * weights * slack_inv * A;
}

float BarrierWalk::generate_proposal_density(VectorXd x, VectorXd z){
    MatrixXd matrix = generate_hessian(x);
    VectorXd d = generate_gaussian_rv(x.rows());

    return sqrt(matrix.determinant()) * exp(term_density * local_norm(x - z, matrix));
}

VectorXd BarrierWalk::generate_sample(VectorXd x){
    MatrixXd matrix = generate_hessian(x).inverse().sqrt();
    VectorXd direction = generate_gaussian_rv(x.rows());
    return x + term_sample * (matrix * direction);
}

MatrixXd BarrierWalk::generate_complete_walk(int num_steps, VectorXd x){
    MatrixXd results = MatrixXd::Zero(num_steps, A.cols());
    float one = 1.0;
    for(int i = 0; i < num_steps; i++){
        VectorXd z = generate_sample(x);
        if(accept_reject(z)){
            float g_x_z = generate_proposal_density(x, z);
            float g_z_x = generate_proposal_density(z, x);
            float alpha = min(one, g_z_x/g_x_z);
            float val = (float)rand()/RAND_MAX;
            x = val < alpha ? z : x;
        }
        results.row(i) = x.transpose();
    }
    return results;
}
