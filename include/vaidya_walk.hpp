#include "barrier_walk.hpp"

class VaidyaWalk: public BarrierWalk{

    public:
        VaidyaWalk() : BarrierWalk(){}

        void initialize(MatrixXd A_p, VectorXd b_p, float r){
            float constant = (r * r)/sqrt(A_p.cols() * A_p.rows());
            float td = (-0.5 / constant);
            float ts = sqrt(constant);
            A = A_p;
            b = b_p;
            BarrierWalk::set_ts(ts);
            BarrierWalk::set_td(td);
        }
        VectorXd generate_weight(VectorXd x);
        VectorXd generate_dikin_weight(VectorXd x);
        MatrixXd generate_dikin_hessian(VectorXd x);
        void printType();
};