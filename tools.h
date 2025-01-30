#ifndef NUMERICAL_LINEAR_ALGEBRA_TOOLS_H
#define NUMERICAL_LINEAR_ALGEBRA_TOOLS_H

#include "eigen/Eigen/Dense"

namespace NLA {
constexpr double EPS = 1e-4;
constexpr double INF = 1e16;

bool IsCloseToZero(double val);

Eigen::Matrix2d GivensRotation(double x, double y);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_TOOLS_H
