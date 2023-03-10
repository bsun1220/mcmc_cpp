#ifndef HEADER_H
#define HEADER_H

#include "common.hpp"

class BarrierWalk{
    public:
        MatrixXd A{};
        VectorXd b{};
        float term_sample{};
        float term_density{};

        BarrierWalk(MatrixXd A_p, VectorXd b_p){
            A = A_p;
            b = b_p;
            term_sample = 0;
            term_density = 0;
        }

        void set_ts(float a);

        void set_td(float b);

        bool accept_reject(VectorXd z);

        float generate_gaussian();

        VectorXd generate_gaussian_rv(int d);

        VectorXd generate_slack(VectorXd x);
        float local_norm(VectorXd v, MatrixXd m);

        VectorXd generate_weight(VectorXd x);

        MatrixXd generate_hessian(VectorXd x);

        float generate_proposal_density(VectorXd x, VectorXd z);

        VectorXd generate_sample(VectorXd x);

        MatrixXd generate_complete_walk(int num_steps, VectorXd x);
};



#endif