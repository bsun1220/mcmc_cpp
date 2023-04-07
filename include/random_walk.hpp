#ifndef RAND_H
#define RAND_H
#include "common.hpp"


class RandomWalk{
    public: 
        MatrixXd A{};
        VectorXd b{};
        float r {};

    RandomWalk(){}

    virtual void initialize(MatrixXd A_p, VectorXd b_p, float r_p);

    bool accept_reject(VectorXd& z);

    float generate_gaussian();

    VectorXd generate_gaussian_rv(int d);

    virtual MatrixXd generate_complete_walk(int num_steps, VectorXd x);
};

#endif