
#include "central.hpp"


VectorXd invert(VectorXd v){
    for (int i = 0; i < v.rows(); i++){
        v(i) = 1/v(i);
    }
    return v;
}

VectorXd find_central_point(MatrixXd A, VectorXd b, double ss, double ts, double te){
    int n = A.rows();
    int d = A.cols();

    VectorXd y = VectorXd::Zero(d + 1);
    y(d) = ss;

    VectorXd c = VectorXd::Zero(d + 1);
    c(d) = 1;

    VectorXd ones = VectorXd::Ones(n) * -1;

    for(int i = 0; i < n; i++){
        double norm = A.row(i).norm();
        A.row(i) = A.row(i)/norm;
        b(i) = b(i)/norm;
    }

    MatrixXd A_tilde(A.rows(), A.cols() + 1);
    A_tilde << A, ones;
    double t = ts;

    VectorXd prev_grad = VectorXd::Zero(d + 1);

    while (t < te){
        VectorXd slack = invert(b - (A_tilde * y));

        VectorXd grad = c + A_tilde.transpose() * slack/t;
        MatrixXd slack_mat = slack.asDiagonal().toDenseMatrix();
        MatrixXd hess = A_tilde.transpose() * slack_mat * slack_mat * A_tilde/t;
        MatrixXd inv_hess = hess.inverse();

        VectorXd new_y = y - 0.5 * (inv_hess * grad);
        if ((prev_grad - grad).norm()/(prev_grad.norm() + 0.0000001) < 0.01){
            t *= 2;
        }
        prev_grad = grad;
        y = new_y;
    }

    VectorXd ans = VectorXd(d);
    for(int i = 0; i < d; i++){
        ans(i) = y(i);
    }
    return ans;
}