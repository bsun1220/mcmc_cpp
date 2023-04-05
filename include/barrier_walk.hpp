#ifndef HEADER_H
#define HEADER_H

#include "common.hpp"

class BarrierWalk{
    public:
        MatrixXd A{};
        VectorXd b{};
        float term_sample{};
        float term_density{};

        BarrierWalk(){
            term_sample = 0;
            term_density = 0;
        }

        virtual void initialize(MatrixXd A_p, VectorXd b_p, float r);

        void set_ts(float a);

        void set_td(float b);

        bool accept_reject(VectorXd& z);

        float generate_gaussian();

        VectorXd generate_gaussian_rv(int d);

        VectorXd generate_slack(VectorXd& x);
        float local_norm(VectorXd v, MatrixXd& m);

        virtual VectorXd generate_weight(VectorXd& x);
        virtual void printType();

        MatrixXd generate_hessian(VectorXd& x);

        float generate_proposal_density(VectorXd& x, VectorXd& z);

        VectorXd generate_sample(VectorXd& x);

        MatrixXd generate_complete_walk(int num_steps, VectorXd& x);
};



#endif