#include "householder_reflection.h"

namespace NLA {
Vector HouseholderVector(const Vector& x) {
    Vector u = x;
    if (x(0) > 0) {
        u(0) += x.norm();
    } else {
        u(0) -= x.norm();
    }
    u.normalize();
    return u;
}

Matrix HouseholderReflection(const Vector& x) {
    Index n = x.size();
    Vector u = HouseholderVector(x);
    return Matrix::Identity(n, n) - 2 * u * u.transpose();
}

void ApplyHouseholderFromLeft(Matrix& A, const Vector& x) {
    Matrix P = HouseholderReflection(x);
    A = P * A;
}

void ApplyHouseholderFromRight(Matrix& A, const Vector& x) {
    Matrix P = HouseholderReflection(x);
    A = A * P;
}
} // namespace NLA
