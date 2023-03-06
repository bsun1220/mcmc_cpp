#include <ifopt/variable_set.h>
#include <ifopt/constraint_set.h>
#include <ifopt/cost_term.h>
#include <ifopt/problem.h>
#include <ifopt/ipopt_solver.h>
#include <iostream>
#include "common.hpp"

using namespace ifopt;
using namespace std;
using namespace Eigen;

class ExVariables : public VariableSet{
    public:
    VectorXd x;

    ExVariables(int num_dim, string name, VectorXd init) : VariableSet(num_dim, name){
        x = init;
    } 
    void SetVariables(const VectorXd& val) override
    {
        x = val;
    }

    VectorXd GetValues() const override{
        return x;
    }

    VecBound GetBounds() const override{
        VecBound bounds(GetRows());
        for(int i = 0; i < x.rows(); i++){
            bounds.at(i) = NoBound;
        }
        return bounds;
    }

};

class ExConstraint1 : public ConstraintSet{
    public:
    MatrixXd A;
    ExConstraint1(int num_dim, string name, MatrixXd A_param) : ConstraintSet(num_dim, name){
        // A is d by n matrix
        A = A_param.transpose();
        
    }

    VectorXd GetValues() const override{
        VectorXd g(GetRows());
        VectorXd input = GetVariables()->GetComponent("var_set1")->GetValues();
        for(int i = 0; i < A.rows(); i++){
            VectorXd A_row = A.row(i);
            //A row is a n dimensional vector
            g(i) = A_row.transpose() * input; 
        }
        return g;
    }

    VecBound GetBounds() const override{
        VecBound b(GetRows());
        for(int i = 0; i < A.rows(); i++){
            b.at(i) = Bounds(-0.00000001, inf);
        }
        return b;
    }
    void FillJacobianBlock (string var_set, Jacobian& jac_block) const override{}

};

class ExConstraint2 : public ConstraintSet{
    public:
    MatrixXd A;
    VectorXd b;
    ExConstraint2(int num_dim, string name, int x_dim, int ind, MatrixXd A_param, VectorXd b_param) : ConstraintSet(num_dim, name){

        MatrixXd newA(x_dim + 2, A_param.rows());
        //A is a (x+2) by n matrix
        //A_param is a n by d matrix, col is a n-dim array, row is a d-dim array
        for(int i = 0; i < x_dim; i++){
            newA.row(i) = A_param.col(i);
        }
        
        newA.row(x_dim) = A_param.col(ind);
        newA.row(x_dim + 1) = b_param;

        A = newA;
        b = VectorXd::Zero(x_dim + 2);
        b(x_dim) = 1;

    }

    VectorXd GetValues() const override{
        VectorXd g(GetRows());
        VectorXd input = GetVariables()->GetComponent("var_set1")->GetValues();
        for(int i = 0; i < A.rows(); i++){
            VectorXd A_row = A.row(i);
            //A row is a n dimensional vector
            g(i) = A_row.transpose() * input; 
        }
        return g;
    }

    VecBound GetBounds() const override{
        VecBound bound(GetRows());
        for(int i = 0; i < b.rows(); i++){
            bound.at(i) = Bounds(b(i),b(i));
        }
        return bound;
    }

    void FillJacobianBlock (string var_set, Jacobian& jac_block) const override{}

};

class ExCost : public CostTerm{
    public:
    ExCost(const std::string& name) : CostTerm(name) {}
    
    double GetCost() const override
    {
        VectorXd x = GetVariables()->GetComponent("var_set1")->GetValues();
        double sum = 0;
        for (int i = 0; i < x.rows(); i++){
            sum += x(i);
        }
        return sum;
    };
    void FillJacobianBlock (string var_set, Jacobian& jac_block) const override{}
};

MatrixXd equal_conversion(MatrixXd A){
    MatrixXd A_tilde (A.rows(), A.cols() + A.rows());
    A_tilde << A, MatrixXd::Identity(A.rows(), A.rows());
    return A_tilde;
}

void find_z(MatrixXd A, VectorXd b, int x_dim){
    int n = A.rows();
    int d = A.cols();
    for(int i = x_dim; i < d; i++){
        cout << "hi" << endl;
    }
}

void reduce_problem(MatrixXd A, VectorXd b){
    MatrixXd newA = equal_conversion(A);
    find_z(newA, b, A.cols());
}

int main(){
    MatrixXd A (4,2);
    A << 1,0,-1,0,0,1,0,-1;
    VectorXd b(4);
    b << 2,2,0,0;

    MatrixXd newA = equal_conversion(A);
    VectorXd init (4);
    init << -1,-1,-1,-1;

    int n = newA.rows();
    int d = newA.cols();
    int x_dim = A.cols();

    int i = 5;
    string name = "var_set1";

    Problem lp; 
    
    lp.AddVariableSet(make_shared<ExVariables>(n, name, init));
    
    lp.AddConstraintSet(make_shared<ExConstraint1>(newA.cols(),name,newA));
      
    lp.AddConstraintSet(make_shared<ExConstraint2>(x_dim + 2, name,x_dim, 
                                                  i, newA, b));
    
    lp.AddCostSet(make_shared<ExCost>(name));

    IpoptSolver ipopt;
    ipopt.Solve(lp);
    ipopt.SetOption("least_square_init_primal", "yes");

    VectorXd sol = lp.GetOptVariables()->GetValues();
    cout << sol << endl;

}