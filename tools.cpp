#include "tools.h"

namespace NLA {
bool IsCloseToZero(double val) {
    return abs(val) < EPS;
}

Eigen::Matrix2d GivensRotation(double x, double y) {
    if (IsCloseToZero(y)) {
        return Eigen::Matrix2d::Identity();
    }

    Eigen::Matrix2d G;
    double r = sqrt(x * x + y * y);
    double c = x / r;
    double s = -y / r;
    G << c, -s, s, c;

    return G;
}
} // namespace NLA
