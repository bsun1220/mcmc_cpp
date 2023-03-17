
#include "facial_reduction.hpp"

int main(){
    MatrixXd A (6,3);
    A << 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1;
    VectorXd b(6);
    b << 1,1,1,1,0,0;

    problem_result fr = reduce_problem(A, b);
    cout << fr.reduced_A << endl;
    cout << fr.reduced_b << endl;


}