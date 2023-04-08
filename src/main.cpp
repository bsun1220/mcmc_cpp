#include <pybind11/pybind11.h>
#include "polywalk.hpp"
#include <pybind11/eigen.h>
using namespace std; 
namespace py = pybind11;

MatrixXd generate_walk(MatrixXd& A, VectorXd& b, string walk_type, float r, int num_sim, float step_size, int max_iter, float grad_lim, double ss, double ts, double te, float err){
    if (walk_type == "dikin"){
        DikinWalk d;
        return full_barrier_run(A, b, d, r, num_sim, ss, ts, te);
    } else if (walk_type == "vaidya"){
        VaidyaWalk v;
        return full_barrier_run(A, b, v, r, num_sim, ss, ts, te);
    } else if (walk_type == "dikinls"){
        DikinLSWalk dl(step_size, max_iter, grad_lim);
        return full_barrier_run(A, b, dl, r, num_sim, ss, ts, te);
    } else if (walk_type == "john"){
        JohnWalk j(step_size, max_iter, grad_lim);
        return full_barrier_run(A, b, j, r, num_sim, ss, ts, te);
    } else if (walk_type == "ball"){
        BallWalk ball;
        return full_walk_run(A, b, ball, r, num_sim, ss, ts, te);
    } else if (walk_type == "hitrun"){
        HitAndRun hr (err);
        return full_walk_run(A, b, hr, r, num_sim, ss, ts, te);
    }
    return A;
}

PYBIND11_MODULE(mcmc, m) {
    m.doc() = "pybind11 poly walk example";
    m.def("generate_walk", &generate_walk, "central function", 
    py::arg("A"), py::arg("b"), py::arg("walk_type"), py::arg("r"), py::arg("num_sim"), 
    py::arg("step_size") = 0.1, py::arg("max_iter") = 100, py::arg("grad_lim") = 0.01, py::arg("ss") = 10000, 
    py::arg("ts") = 0.00001, py::arg("te") =10000, py::arg("err") = 0.01);

}

int main(){
    return 0;
}