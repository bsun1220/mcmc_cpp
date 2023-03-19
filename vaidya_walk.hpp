#include "barrier_walk.hpp"

class VaidyaWalk: public BarrierWalk{

    public:
        VaidyaWalk() : BarrierWalk(){}

        void initialize(MatrixXd A_p, VectorXd b_p, float r){
             float constant = (r * r)/sqrt(A_p.cols() * A_p.rows());
            term_density = (-0.5 / constant);
            term_sample = sqrt(constant);
            A = A_p;
            b = b_p;
            BarrierWalk::set_ts(term_sample);
            BarrierWalk::set_td(term_density);
        }
        VectorXd generate_weight(VectorXd x);



};