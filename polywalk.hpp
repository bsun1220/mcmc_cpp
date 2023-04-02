#include "common.hpp"
#include "barrier_walk.hpp"
#include "john_walk.hpp"
#include "dikinls_walk.hpp"
#include "vaidya_walk.hpp"
#include "dikin_walk.hpp"
#include "central.hpp"
#include "facial_reduction.hpp"

VectorXd convert_back(VectorXd z, VectorXd pb, MatrixXd M_inv, int x_dim){
    VectorXd val (z.rows() + pb.rows());
    val << pb, z;
    return (M_inv * val).head(x_dim);
};

MatrixXd full_run(MatrixXd A, VectorXd b, BarrierWalk& walk,float r, int num_sim){
    int x_dim = A.cols();

    problem_result fr = reduce_problem(A, b);
    if (fr.reduced){
        MatrixXd reduced_A = fr.reduced_A;
        MatrixXd reduced_b = fr.reduced_b; 
        VectorXd pb = fr.b_tilde;
        MatrixXd M_inv = fr.M.inverse();

        VectorXd x = find_central_point(reduced_A, reduced_b, 10000.0, 0.00001, 10000.0);
        walk.initialize(reduced_A, reduced_b, r);
        MatrixXd results = walk.generate_complete_walk(num_sim, x);
        MatrixXd res(results.rows(), x_dim);
        for(int i = 0; i < results.rows(); i++){
            res.row(i) = convert_back(results.row(i), pb, M_inv, x_dim);
        }
        return res; 

    } else {
        walk.initialize(A, b, r);
        walk.printType();
        VectorXd x = find_central_point(A, b, 10000.0, 0.00001, 100000);
        MatrixXd results = walk.generate_complete_walk(num_sim, x);
        return results;
    }
};

