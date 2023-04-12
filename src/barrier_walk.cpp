
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

bool BarrierWalk::accept_reject(VectorXd& z){
    return ((A * z) - b).maxCoeff() <= 0;
}

float BarrierWalk::generate_gaussian(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    float r1 = dis(gen);
    float r2 = dis(gen);

    return sqrt(-2.0 * log(r1)) * cos((2.0 * M_PI * r2));
}

VectorXd BarrierWalk::generate_gaussian_rv(int d){
    VectorXd v(d);
    for(int i = 0; i < d; i++){
        v(i) = generate_gaussian();
    }
    return v;
}

VectorXd BarrierWalk::generate_slack(VectorXd& x){
    return (b - (A * x));
}

float BarrierWalk::local_norm(VectorXd v, MatrixXd& m){
    return ((v.transpose() * m) * v)(0);
}

VectorXd BarrierWalk::generate_weight(VectorXd& x){
    int d = b.rows();
    return VectorXd::Zero(d);
}

MatrixXd BarrierWalk::generate_hessian(VectorXd& x){
    MatrixXd weights = generate_weight(x).asDiagonal().toDenseMatrix();
    MatrixXd slack_inv = generate_slack(x).cwiseInverse().asDiagonal().toDenseMatrix();

    return A.transpose() * slack_inv * weights * slack_inv * A;
}

float BarrierWalk::generate_proposal_density(VectorXd& x, VectorXd& z){
    MatrixXd matrix = generate_hessian(x);
    VectorXd d = generate_gaussian_rv(x.rows());

    return sqrt(matrix.determinant()) * exp(term_density * local_norm(x - z, matrix));
}

VectorXd BarrierWalk::generate_sample(VectorXd& x){
    MatrixXd matrix = generate_hessian(x).inverse().sqrt();
    VectorXd direction = generate_gaussian_rv(x.rows());
    return x + term_sample * (matrix * direction);
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
        VectorXd z = generate_sample(x);
        if(accept_reject(z)){
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
