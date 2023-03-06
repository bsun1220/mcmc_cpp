
#include <iostream>
#include <algorithm>
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
#include <ifopt/bounds.h>
#include <ifopt/variable_set.h>
#include <ifopt/constraint_set.h>
#include <ifopt/problem.h>
#include <ifopt/ipopt_solver.h>
#include <pybind11/pybind11.h>
using namespace std;
using namespace Eigen;

int main(){
    int t = 1;
    VectorXd b(2);
    b << 0, 2;
    cout << b << endl;
    ifopt::Problem nlp;
}