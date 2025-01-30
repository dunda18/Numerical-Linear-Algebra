#ifndef NUMERICAL_LINEAR_ALGEBRA_HESSENBERG_FORM_H
#define NUMERICAL_LINEAR_ALGEBRA_HESSENBERG_FORM_H

#include "eigen/Eigen/Dense"

namespace NLA {
Eigen::MatrixXd GetHessenbergForm(Eigen::MatrixXd A);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_HESSENBERG_FORM_H
