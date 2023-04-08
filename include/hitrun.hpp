#include "random_walk.hpp"


class HitAndRun: public RandomWalk{

    float err {};
    public:
        HitAndRun(float err_p) : RandomWalk() {
            err = err_p; 
        }

        void initialize(MatrixXd A_p, VectorXd b_p, float r_p){
            A = A_p;
            b = b_p;
            r = r_p;
        }

        double distance(VectorXd& x, VectorXd&y);

        double binary_search(VectorXd direction, VectorXd x);

        MatrixXd generate_complete_walk(int num_steps, VectorXd x);

};