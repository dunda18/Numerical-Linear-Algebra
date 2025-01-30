#ifndef NUMERICAL_LINEAR_ALGEBRA_EIGEN_SOLVER_H
#define NUMERICAL_LINEAR_ALGEBRA_EIGEN_SOLVER_H

#include "eigen/Eigen/Dense"

namespace NLA {
Eigen::VectorXd SimpleQR(Eigen::MatrixXd A);

Eigen::VectorXd HessenbergQR(const Eigen::MatrixXd& A);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_EIGEN_SOLVER_H
