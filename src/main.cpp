#include <pybind11/pybind11.h>
#include "polywalk.hpp"
#include <pybind11/eigen.h>
using namespace std; 
namespace py = pybind11;

MatrixXd generate_walk(MatrixXd& A, VectorXd& b, string walk_type, float r, int num_sim, float ss, int mi, float gl){
    if (walk_type == "dikin"){
        DikinWalk d;
        return full_run(A, b, d, r, num_sim);
    } else if (walk_type == "vaidya"){
        VaidyaWalk v;
        return full_run(A, b, v, r, num_sim);
    } else if (walk_type == "dikinls"){
        DikinLSWalk dl(ss, mi, gl);
        return full_run(A, b, dl, r, num_sim);
    } else if (walk_type == "john"){
        JohnWalk j(ss, mi, gl);
        return full_run(A, b, j, r, num_sim);
    }
    return A;
}

PYBIND11_MODULE(mcmc, m) {
    m.doc() = "pybind11 poly walk example";
    m.def("generate_walk", &generate_walk, "central function", 
    py::arg("A"), py::arg("b"), py::arg("walk_type"), py::arg("r"), py::arg("num_sim"),
    py::arg("ss") = 0.1, py::arg("mi") = 250, py::arg("gl") = 0.01);

}

int main(){
    return 0;
}