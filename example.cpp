#include <pybind11/pybind11.h>
#include "facial_reduction.hpp"
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

PYBIND11_MODULE(mcmc, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");
    m.def("rand_val", &rand_val, "A function that adds two numbers");
}

int main(){
    MatrixXd A (4,2);
    A << 1, 0, -1, 0, 0, 1, 0, -1;
    VectorXd b(4);
    b << 1, 1, 0, 0;
    reduce_problem(A, b);
}