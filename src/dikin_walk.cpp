#include "dikin_walk.hpp"

VectorXd DikinWalk::generate_weight(VectorXd& x){
    int d = b.rows();
    return VectorXd::Ones(d);
}

void DikinWalk::printType(){
    cout << "Dikin Walk" << endl;
}