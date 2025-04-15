#ifndef NUMERICAL_LINEAR_ALGEBRA_HOUSEHOLDER_REFLECTION_H
#define NUMERICAL_LINEAR_ALGEBRA_HOUSEHOLDER_REFLECTION_H

#include "linalg.h"

namespace NLA {
Vector HouseholderVector(const Vector& x);

Matrix HouseholderReflection(const Vector& x);

void ApplyHouseholderFromLeft(Matrix& A, const Vector& x);

void ApplyHouseholderFromRight(Matrix& A, const Vector& x);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_HOUSEHOLDER_REFLECTION_H
