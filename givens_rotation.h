#ifndef NUMERICAL_LINEAR_ALGEBRA_GIVENS_ROTATION_H
#define NUMERICAL_LINEAR_ALGEBRA_GIVENS_ROTATION_H

#include "linalg.h"

namespace NLA {
Matrix2 GivensRotation(double x, double y);

Matrix GivensRotation(Index n, Index i, Index j, double x, double y);

void ApplyGivensFromLeft(Matrix& A, Index i, Index j, double x, double y);

void ApplyGivensFromRight(Matrix& A, Index i, Index j, double x, double y);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_GIVENS_ROTATION_H
