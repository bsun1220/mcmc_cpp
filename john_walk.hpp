#include "barrier_walk.hpp"

class JohnWalk: public BarrierWalk{

    public:

        JohnWalk() : BarrierWalk(){}
        
        void initialize(MatrixXd A_p, VectorXd b_p, float r){
            float constant = (r * r)/b_p.rows();
            term_density = (-0.5 / constant);
            term_sample = sqrt(constant);
            A = A_p;
            b = b_p;
            BarrierWalk::set_ts(term_sample);
            BarrierWalk::set_td(term_density);
        }

        VectorXd vect_pow(VectorXd x, float alpha);
        VectorXd gradient_descent(VectorXd x, float adj, int sim);
        VectorXd generate_weight(VectorXd x);
};