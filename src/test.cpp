#include "polywalk.hpp"


int main(){
    MatrixXd A (2,1);
    A << 1, -1;
    VectorXd b (2);
    b << 1, 0;

    DikinWalk d;

    MatrixXd res = full_barrier_run(A, b, d, 0.4, 10, 10000, 0.00001, 10000);
    cout << res << endl;
    
}