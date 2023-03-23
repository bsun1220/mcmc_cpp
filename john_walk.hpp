#include "barrier_walk.hpp"

class JohnWalk: public BarrierWalk{

    public:
    float step_size{};
    float max_iter{};
        JohnWalk(float ss, float mi) : BarrierWalk(){
            step_size = ss;
            max_iter = mi;
        }
        
        void initialize(MatrixXd A_p, VectorXd b_p, float r){
            float constant = (r * r)/b_p.rows();
            float td = (-0.5 / constant);
            float ts = sqrt(constant);
            A = A_p;
            b = b_p;
            BarrierWalk::set_ts(ts);
            BarrierWalk::set_td(td);
        }

        VectorXd vect_pow(VectorXd x, float alpha);
        VectorXd gradient_descent(VectorXd x, float adj, int sim);
        VectorXd generate_weight(VectorXd x);

        void printType();
};