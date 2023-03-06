#include "common.hpp"


MatrixXd equal_conversion(MatrixXd A){
    MatrixXd A_tilde (A.rows(), A.cols() + A.rows());
    A_tilde << A, MatrixXd::Identity(A.rows(), A.rows());
    return A_tilde;
}

MatrixXd facial_reduction(VectorXd z){
    int d = z.rows();
    for(int i = 0; i < d; i++){
        z(i) = (double)(round(z(i) * 1000))/1000;
    }
    vector <int> indices;
    for(int i = 0; i < d; i++){
        if(z(i) == 0){
            indices.push_back(i);
        }
    }
    MatrixXd m (d, 0);
    for(int val : indices){
        VectorXd arr = VectorXd::Zero(d);
        arr(val) = 1; 
        MatrixXd new_m (d, m.cols() + 1);
        new_m << m, arr; 
        m = new_m;
    }
    return m;
}