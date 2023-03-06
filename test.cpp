
#include "dikin_walk.hpp"
#include "john_walk.hpp"
#include "dikinls_walk.hpp"
#include "central.cpp"

int main(){
    srand(time(NULL));

    MatrixXd A(3,2);

    A << -1, 0,
        0, -1,
        1, 1;
    
    VectorXd b(3);
    b << 0,0, 1;
    int a = 1;

    VectorXd x = find_central_point(A, b, 10000, 0.00001, 10000);

    DikinLSWalk walk(A, b, 1.0);

    cout << walk.generate_complete_walk(1000, x) << endl;

}