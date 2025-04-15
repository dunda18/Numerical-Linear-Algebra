#ifndef NUMERICAL_LINEAR_ALGEBRA_EIGEN_SOLVER_H
#define NUMERICAL_LINEAR_ALGEBRA_EIGEN_SOLVER_H

#include "linalg.h"

namespace NLA {
Vector SimpleQR(Matrix A);

Vector HessenbergQR(const Matrix& A);

Vector RayleighQR(const Matrix& A);

Vector FrancisQR(const Matrix& A);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_EIGEN_SOLVER_H
