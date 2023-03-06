#include <iostream>
#include "common.hpp"
#include <ifopt/problem.h>
#include <ifopt/ipopt_solver.h>
#include <ifopt/test_vars_constr_cost.h>

using namespace ifopt;

int main()
{
  // 1. define the problem
  Problem nlp;
  nlp.AddVariableSet  (make_shared<ExVariables>());
  nlp.AddConstraintSet(make_shared<ExConstraint>());
  nlp.AddCostSet      (make_shared<ExCost>());
  nlp.PrintCurrent();

  // 2. choose solver and options
  IpoptSolver ipopt;
  ipopt.SetOption("linear_solver", "mumps");
  ipopt.SetOption("jacobian_approximation", "exact");

  // 3 . solve
  ipopt.Solve(nlp);
  VectorXd x = nlp.GetOptVariables()->GetValues();
  cout << x.transpose() << endl;

  // 4. test if solution correct
  double eps = 1e-5; //double precision
  assert(1.0-eps < x(0) && x(0) < 1.0+eps);
  assert(0.0-eps < x(1) && x(1) < 0.0+eps);
}
