#include "barrier_walk.hpp"

class VaidyaWalk: public BarrierWalk{

    public:

        MatrixXd dhess {};
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
        void generate_weight(VectorXd& x);
        void generate_dikin_hessian(VectorXd& x);
        void printType();
};