#ifndef HEADER_H
#define HEADER_H

#include "common.hpp"

class BarrierWalk{
    public:
        MatrixXd A{};
        VectorXd b{};
        float term_sample{};
        float term_density{};

        bool acc_rej{};
        VectorXd slack{}; 
        MatrixXd hess{};
        VectorXd z{};
        MatrixXd weights{};
        
        BarrierWalk(){
            term_sample = 0;
            term_density = 0;
        }

        virtual void initialize(MatrixXd A_p, VectorXd b_p, float r);

        void set_ts(float a);

        void set_td(float b);

        void accept_reject(VectorXd& z);

        float generate_gaussian();

        VectorXd generate_gaussian_rv(int d);

        void generate_slack(VectorXd& x);
        float local_norm(VectorXd v, MatrixXd& m);

        virtual void generate_weight(VectorXd& x);
        virtual void printType();

        void generate_hessian(VectorXd& x);

        float generate_proposal_density(VectorXd& x, VectorXd& z);

        void generate_sample(VectorXd& x);

        MatrixXd generate_complete_walk(int num_steps, VectorXd& x);
};



#endif