
#include "barrier_walk.hpp"

void BarrierWalk::initialize(MatrixXd A_p, VectorXd b_p, float r){
    A = A_p;
    b = b_p;
    r = r; 
}

void BarrierWalk::set_ts(float a){
    term_sample = a; 
}

void BarrierWalk::set_td(float b){
    term_density = b; 
}

void BarrierWalk::accept_reject(VectorXd& z){
    acc_rej = ((A * z) - b).maxCoeff() <= 0;
}

float BarrierWalk::generate_gaussian(){
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<float> dis(0.0, 1.0);

    float r1 = dis(gen);
    return r1;
}

VectorXd BarrierWalk::generate_gaussian_rv(int d){
    VectorXd v(d);
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> dis(0.0, 1.0);
    for(int i = 0; i < d; i++){
        v(i) = dis(gen);
    }
    return v;
}

void BarrierWalk::generate_slack(VectorXd& x){
    slack = (b - (A * x));
}

float BarrierWalk::local_norm(VectorXd v, MatrixXd& m){
    return ((v.transpose() * m) * v)(0);
}

void BarrierWalk::generate_weight(VectorXd& x){
    int d = b.rows();
    weights = VectorXd::Zero(d).asDiagonal().toDenseMatrix();
}

void BarrierWalk::generate_hessian(VectorXd& x){
    generate_weight(x);
    generate_slack(x);
    MatrixXd slack_inv = slack.cwiseInverse().asDiagonal().toDenseMatrix();
    hess = A.transpose() * slack_inv * weights * slack_inv * A;
}

float BarrierWalk::generate_proposal_density(VectorXd& x, VectorXd& z){
    generate_hessian(x);
    VectorXd d = generate_gaussian_rv(x.rows());
    return sqrt(hess.determinant()) * exp(term_density * local_norm(x - z, hess));
}

void BarrierWalk::generate_sample(VectorXd& x){
    generate_hessian(x);
    MatrixXd matrix = hess.inverse().sqrt();
    VectorXd direction = generate_gaussian_rv(x.rows());
    z = x + term_sample * (matrix * direction);
}

void BarrierWalk::printType(){
    cout << "Generic Barrier" << endl;
}

MatrixXd BarrierWalk::generate_complete_walk(int num_steps, VectorXd& x){
    MatrixXd results = MatrixXd::Zero(num_steps, A.cols());
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    float one = 1.0;
    for(int i = 0; i < num_steps; i++){
        generate_sample(x);
        accept_reject(z);
        if(acc_rej){
            float g_x_z = generate_proposal_density(x, z);
            float g_z_x = generate_proposal_density(z, x);
            float alpha = min(one, g_z_x/g_x_z);
            float val = dis(gen);
            x = val < alpha ? z : x;
        }
        results.row(i) = x.transpose();
    }
    return results;
}
