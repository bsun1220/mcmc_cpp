#include <pybind11/pybind11.h>
#include "polywalk.hpp"
#include <pybind11/eigen.h>
using namespace std; 
namespace py = pybind11;


float add(float i, float j) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

float rand_val(){
    return rand();
}

MatrixXd generate_walk(MatrixXd& A, VectorXd& b, string walk_type, float r, int num_sim){
    if (walk_type == "dikin"){
        DikinWalk d;
        return full_run(A, b, d, r, num_sim);
    } else if (walk_type == "vaidya"){
        VaidyaWalk v;
        return full_run(A, b, v, r, num_sim);
    } else if (walk_type == "dikinls"){
        DikinLSWalk dl(0.1, 100, 0.1);
        return full_run(A, b, dl, r, num_sim);
    } else if (walk_type == "john"){
        JohnWalk j(0.1, 100, 0.1);
        return full_run(A, b, j, r, num_sim);
    }
    return A;
}

const MatrixXd ret_mat(){
    return MatrixXd::Zero(5, 5);
}

PYBIND11_MODULE(mcmc, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");
    m.def("rand_val", &rand_val, "A function that adds two numbers");
    m.def("generate_walk", &generate_walk, "central function");
    m.def("ret_mat", &ret_mat, "test function");
}

int main(){
    MatrixXd A (4,2);
    A << 1, 0, -1, 0, 0, 1, 0, -1;
    VectorXd b(4);
    b << 1, 1, 0, 0;
    MatrixXd res1 = generate_walk(A, b, "dikin", 0.4, 10);
    cout << res1 << endl;
    MatrixXd res2 = generate_walk(A, b, "vaidya", 0.4, 10);
    cout << res2 << endl;
}