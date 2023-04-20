#include "polywalk.hpp"


int main(){
    MatrixXd A (4,2);
    A << 1, 0, -1, 0, 0, 1, 0, -1;
    VectorXd b (4);
    b << 1, 0, 1, 0;

    VaidyaWalk d;

    MatrixXd res = full_barrier_run(A, b, d, 0.4, 100, 10000, 0.00001, 10000);
    cout << res << endl;
    
}