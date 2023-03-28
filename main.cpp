#include "common.hpp"
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
}

int main(){
    srand(time(NULL));

    MatrixXd A (4,2);
    A << 1, 0, -1, 0, 0, 1, 0, -1;
    VectorXd b(4);
    b << 1, 0, 1, 0;

   /*
    MatrixXd A(4,2);
    A << 1, 0, -1, 0, 0, 1, 0, -1;
    VectorXd b(4);
    b << 2, 2, 0, 0;*/

    /*
    MatrixXd A(6,3);
    A << 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1;
    VectorXd b(6);
    b << 1, 1, 0, 0, 0, 0;*/

    /*
    MatrixXd A(6,3);
    A << 1, 1, 0, -1, -1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1;
    VectorXd b (6);
    b << 1, -1, 1, 1, 1, 1;*/

    /*
    MatrixXd A (4,2);
    A << 1, 0, -1, 0, 1, 1, -1,-1;
    VectorXd b(4);
    b << 1, 1, 1, -1;*/

    VaidyaWalk v;
    DikinLSWalk dl(0.1, 100, 0.01);
    JohnWalk j(0.1, 100, 0.01);
    DikinWalk d;

    cout << full_run(A, b, v, 0.4, 10) << endl;
    cout << full_run(A, b, dl, 0.4, 10) << endl;
    cout << full_run(A, b, j, 0.4, 10) << endl;
    cout << full_run(A, b, d, 0.4, 10) << endl;

}