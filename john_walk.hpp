#include "barrier_walk.hpp"

class JohnWalk: public BarrierWalk{

    public:

        JohnWalk(MatrixXd A_p, VectorXd b_p, float r) : BarrierWalk(A_p, b_p){
            float constant = (r * r)/b.rows();

            term_density = (-0.5 / constant);
            term_sample = sqrt(constant);

            BarrierWalk::set_ts(term_sample);
            BarrierWalk::set_td(term_density);
        }

        VectorXd vect_pow(VectorXd x, float alpha);
        VectorXd gradient_descent(VectorXd x, float adj, int sim);
        VectorXd generate_weight(VectorXd x);
};