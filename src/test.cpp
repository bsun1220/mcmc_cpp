#include "polywalk.hpp"


int main(){
    MatrixXd A (4,2);
    A << 1, 0, -1, 0, 0, 1, 0, -1;
    VectorXd b (4);
    b << 1, 0, 1, 0;

    HitAndRun hr(0.4);

    MatrixXd res = full_walk_run(A, b, hr, 0.4, 10, 10000, 0.00001, 10000);
    cout << res << endl;
    
}