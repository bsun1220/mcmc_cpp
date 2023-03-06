
#include "barrier_walk.hpp"

class DikinWalk: public BarrierWalk{

    public:

        DikinWalk(MatrixXd A_p, VectorXd b_p, float r) : BarrierWalk(A_p, b_p){
            float constant = (r * r)/b.rows();

            term_density = (-0.5 / constant);
            term_sample = sqrt(constant);

            BarrierWalk::set_ts(term_sample);
            BarrierWalk::set_td(term_density);
        }
};