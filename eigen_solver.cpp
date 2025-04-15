#include "eigen_solver.h"
#include "hessenberg_form.h"
#include "tools.h"
#include "givens_rotation.h"
#include "householder_reflection.h"

namespace NLA {
Vector SimpleQR(Matrix A) {
    assert(A.rows() == A.cols());

    Index n = A.rows();
    for (int iter = 0; !IsUpperTriangular(A) && iter < MAX_ITER; ++iter) {
        Matrix Q = Matrix::Identity(n, n);
        Matrix R = std::move(A);

        for (Index j = 0; j < n; ++j) {
            for (Index i = n - 1; i > j; --i) {
                Matrix G = Matrix::Identity(n, n);
                G.block(i - 1, i - 1, 2, 2) = GivensRotation(R(i - 1, j), R(i, j));
                R = G * R;
                Q = Q * G.transpose();
            }
        }

        A = R * Q;
    }

    return A.diagonal();
}

Vector HessenbergQR(const Matrix& A) {
    assert(A.rows() == A.cols());

    Matrix H = GetHessenbergForm(A);
    Index n = H.rows();
    for (int iter = 0; !IsHessenbergUpperTriangular(H) && iter < MAX_ITER; ++iter) {
        std::vector<Matrix2> G(n - 1);
        for (Index k = 0; k < n - 1; ++k) {
            G[k] = GivensRotation(H(k, k), H(k + 1, k));
            H.block(k, k, 2, n - k) = G[k] * H.block(k, k, 2, n - k);
        }

        for (Index k = 0; k < n - 1; ++k) {
            H.block(0, k, k + 2, 2) = H.block(0, k, k + 2, 2) * G[k].transpose();
        }
    }

    return H.diagonal();
}

Vector RayleighQR(const Matrix& A) {
    assert(A.rows() == A.cols());

    Matrix H = GetHessenbergForm(A);
    Index n = H.rows();
    for (Index m = n - 1; m > 0; --m) {
        while (!IsCloseToZero(H(m, m - 1))) {
            double sigma = H(m, m);
            H.diagonal() -= sigma * Vector::Ones(n);

            std::vector<Matrix2> G(n - 1);
            for (Index k = 0; k < n - 1; ++k) {
                G[k] = GivensRotation(H(k, k), H(k + 1, k));
                H.block(k, k, 2, n - k) = G[k] * H.block(k, k, 2, n - k);
            }

            for (Index k = 0; k < n - 1; ++k) {
                H.block(0, k, k + 2, 2) = H.block(0, k, k + 2, 2) * G[k].transpose();
            }

            H.diagonal() += sigma * Vector::Ones(n);
        }
    }

    return H.diagonal();
}
} // namespace NLA
