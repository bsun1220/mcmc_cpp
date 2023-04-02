#include "common.hpp"
#include <ifopt/variable_set.h>
#include <ifopt/constraint_set.h>
#include <ifopt/cost_term.h>
#include <ifopt/problem.h>
#include <ifopt/ipopt_solver.h>
using namespace ifopt;
using namespace Eigen;

struct z_result{
    bool found_sol; 
    VectorXd z; 
};

struct fr_result{
    MatrixXd A;
    VectorXd b; 
};

struct problem_result{
    MatrixXd reduced_A;
    VectorXd reduced_b; 
    bool reduced;
    VectorXd b_tilde;
    MatrixXd M;
};

problem_result reduce_problem(MatrixXd A, VectorXd b);