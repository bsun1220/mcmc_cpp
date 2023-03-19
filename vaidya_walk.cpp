#include "vaidya_walk.hpp"

VectorXd VaidyaWalk::generate_weight(VectorXd x){
            MatrixXd hess = BarrierWalk::generate_hessian(x);
            MatrixXd slack_inv = BarrierWalk::generate_slack(x).asDiagonal().toDenseMatrix().inverse();

            MatrixXd weights_mat = slack_inv * A * hess * A.transpose() * slack_inv;

            VectorXd weights = weights_mat.diagonal();

            for(int i = 0; i < weights.rows(); i++){
                weights(i) += A.cols()/A.rows();
            }

            return weights;
}
