#include <ifopt/variable_set.h>
#include <ifopt/constraint_set.h>
#include <ifopt/cost_term.h>
#include <ifopt/problem.h>
#include <ifopt/ipopt_solver.h>
#include <iostream>
#include "common.hpp"
#include <pybind11/pybind11.h>

using namespace ifopt;
using namespace std;
using namespace Eigen;

double round_up(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return round(value * multiplier) / multiplier;
}


MatrixXd make_full_rank(MatrixXd mat){
    if(mat.rows() == mat.cols()){
        return mat; 
    }
    HouseholderQR <MatrixXd> qr(mat.cols(), mat.rows());
    qr.compute(mat.transpose());
    MatrixXd q = qr.householderQ();
    MatrixXd r = q.inverse() * mat.transpose();
 
    MatrixXd iden = MatrixXd::Identity(q.rows(), q.rows());
    MatrixXd new_r (q.rows(), q.rows());
    for(int i = 0; i < r.cols(); i++){
        new_r.col(i) = r.col(i);
    }
    for(int i = r.cols(); i < q.rows(); i++){
        new_r.col(i) = iden.col(i);
    }

    MatrixXd ans = (q * new_r).transpose();
    
    for(int i = 0; i < ans.rows(); i++){
        for(int j = 0; j < ans.cols(); j++){
            ans.coeffRef(i,j) = round_up(ans.coeffRef(i,j), 10);
        }
    }
    

    return ans;
}

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

        A = A_param;
        
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
            b.at(i) = Bounds(-inf, 0);
        }
        return b;
    }
    void FillJacobianBlock (string var_set, Jacobian& jac_block) const override{}

};

class ExConstraint2 : public ConstraintSet{
    public:
    MatrixXd A;
    VectorXd b;
    ExConstraint2(int num_dim, string name, MatrixXd A_param, VectorXd b_param) : ConstraintSet(num_dim, name){
        A = A_param;
        b = b_param;

    }

    VectorXd GetValues() const override{
        VectorXd g(GetRows());
        VectorXd input = GetVariables()->GetComponent("var_set1")->GetValues();
        for(int i = 0; i < A.rows(); i++){
            VectorXd A_row = A.row(i);
            //A row is a n dimensional vector
            g(i) = round_up(A_row.transpose() * input, 10); 
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
    ExCost(string name) : CostTerm(name) {
    }
    
    double GetCost() const override
    {
        cout << "hello" << endl;
        VectorXd x = GetVariables()->GetComponent("var_set1")->GetValues();
        cout << " hello" << endl;
        return x(x.rows() - 1);
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
    MatrixXd A (6,3);
    A << 1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1;
    VectorXd b(6);
    b << 1,1,1,1,0,0;
    MatrixXd newA = equal_conversion(A);
    int n = newA.rows();
    int d = newA.cols();
    int x_dim = A.cols();

    int ind = 7;

    MatrixXd eqA(x_dim + 2, newA.rows());
    for(int i = 0; i < x_dim; i++){
            eqA.row(i) = newA.col(i);
    }
    eqA.row(x_dim) = newA.col(ind);
    eqA.row(x_dim + 1) = b;

    eqA = make_full_rank(eqA);

    
    VectorXd eqb = VectorXd::Zero(eqA.rows());
    eqb(x_dim) = 1;

    VectorXd init = eqA.inverse() * eqb;
    double delta = ((-1 * newA).transpose() * init).maxCoeff();
    VectorXd temp (eqA.rows() + 1);
    for(int i =0 ; i < eqA.rows(); i++){
        temp(i) = init(i);
    }
    temp(eqA.rows()) = delta;
    init = temp;

    MatrixXd ineqA (newA.rows() + 1, newA.cols());
    for(int i = 0; i < newA.rows(); i++){
        ineqA.row(i) = -1 * newA.row(i);
    }
    VectorXd temp_row(newA.cols());
    for(int i = 0; i < newA.cols(); i++){
        temp_row(i) = -1;
    }

    ineqA.row(newA.rows()) = temp_row;
    MatrixXd temp_m = ineqA.transpose();
    ineqA = temp_m;

    MatrixXd temp_eqA (eqA.rows(), eqA.cols() + 1);
    for(int i = 0; i < eqA.cols(); i++){
        temp_eqA.col(i) = eqA.col(i);
    }
    temp_eqA.col(eqA.cols()) = VectorXd::Zero(eqA.rows());
    eqA = temp_eqA;

    cout << eqA * init << endl;
    cout << "--------" << endl;
    cout << eqb << endl;
    cout << "----------" << endl;
    cout << ineqA * init << endl;
    
    cout << "-------" << endl;
    cout << init << endl;

    string name = "var_set1";
    Problem lp;
    lp.AddVariableSet(make_shared<ExVariables>(n + 1, name, init));
    lp.AddConstraintSet(make_shared<ExConstraint1>(ineqA.rows(),name,ineqA));
    lp.AddConstraintSet(make_shared<ExConstraint2>(eqA.rows(),name,eqA, eqb));
    lp.AddCostSet(make_shared<ExCost>(name));
    IpoptSolver ipopt;
    ipopt.Solve(lp);

    VectorXd sol = lp.GetOptVariables()->GetValues();
    cout << sol << endl;


    

}