#include "dikin_walk.hpp"

void DikinWalk::generate_weight(VectorXd& x){
    int d = b.rows();
    weights = MatrixXd::Identity(d, d);
}

void DikinWalk::printType(){
    cout << "Dikin Walk" << endl;
}