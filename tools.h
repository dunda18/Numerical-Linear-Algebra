#ifndef NUMERICAL_LINEAR_ALGEBRA_TOOLS_H
#define NUMERICAL_LINEAR_ALGEBRA_TOOLS_H

#include "linalg.h"

namespace NLA {
constexpr double EPS = 1e-4;
constexpr double INF = 1e16;
constexpr int MAX_ITER = 1000000;

bool IsCloseToZero(double val);

bool IsUpperTriangular(const Matrix& A);

bool IsHessenbergUpperTriangular(const Matrix& H);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_TOOLS_H
