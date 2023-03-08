
#include "dikin_walk.hpp"
#include "john_walk.hpp"
#include "dikinls_walk.hpp"
#include "common.hpp"

MatrixXd make_full_rank(MatrixXd mat){
    if(mat.rows() == mat.cols()){
        return mat; 
    }
    FullPivHouseholderQR <MatrixXd> qr(mat.cols(), mat.rows());
    qr.compute(mat.transpose());
    MatrixXd q = qr.matrixQ();
    MatrixXd r = qr.matrixQR().triangularView<Upper>();

    MatrixXd iden = MatrixXd::Identity(q.rows(), q.rows());
    MatrixXd new_r (q.rows(), q.rows());
    for(int i = 0; i < r.cols(); i++){
        new_r.col(i) = r.col(i);
    }
    for(int i = r.cols(); i < q.rows(); i++){
        new_r.col(i) = iden.col(i);
    }
    return (q * new_r).transpose();
}

int main(){
    srand(time(NULL));

    VectorXd b(3);
    b << 0,0, 1;

   // MatrixXd A (3,4);
   // A << 1, 0, 1, 0, -1, 0, 0, 1, 0, 1, 0, 0;
   MatrixXd A(5,7);
   A << 1,0,0,1,0,0,0,
        -1,0,0,0,1,0,0,
        0,1,0,0,0,1,0,
        0,-1,0,0,0,0,1,
        0,0,1,0,0,0,0;

    cout << make_full_rank(A) << endl;
}