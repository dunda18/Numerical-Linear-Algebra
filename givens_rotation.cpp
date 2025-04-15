#include "givens_rotation.h"
#include "tools.h"

namespace NLA {
Matrix2 GivensRotation(double x, double y) {
    if (IsCloseToZero(y)) {
        return Matrix2::Identity();
    }

    Matrix2 G;
    double r = sqrt(x * x + y * y);
    double c = x / r;
    double s = -y / r;
    G << c, -s, s, c;

    return G;
}

Matrix GivensRotation(Index n, Index i, Index j, double x, double y) {
    assert(std::clamp(i, 0l, n - 1) == i);
    assert(std::clamp(j, 0l, n - 1) == j);

    Matrix G = Matrix::Identity(n, n);
    Matrix2 g = GivensRotation(x, y);

    G(i, i) = g(0, 0);
    G(i, j) = g(0, 1);
    G(j, i) = g(1, 0);
    G(j, j) = g(1, 1);

    return G;
}

void ApplyGivensFromLeft(Matrix& A, Index i, Index j, double x, double y) {
    Index n = A.rows();
    Matrix G = GivensRotation(n, i, j, x, y);
    A = G * A;
}

void ApplyGivensFromRight(Matrix& A, Index i, Index j, double x, double y) {
    Index n = A.cols();
    Matrix G = GivensRotation(n, i, j, x, y);
    A = A * G.transpose();
}
} // namespace NLA
