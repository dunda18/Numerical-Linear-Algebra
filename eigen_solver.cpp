#include "eigen_solver.h"
#include "hessenberg_form.h"
#include "tools.h"

namespace NLA {
Eigen::VectorXd SimpleQR(Eigen::MatrixXd A) {
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("The matrix must be square");
    }

    Eigen::Index n = A.rows();
    bool finish = false;
    while (!finish) {
        Eigen::MatrixXd Q = Eigen::MatrixXd::Identity(n, n);
        Eigen::MatrixXd R = A;

        for (Eigen::Index j = 0; j < n; ++j) {
            for (Eigen::Index i = n - 1; i > j; --i) {
                Eigen::MatrixXd G = Eigen::MatrixXd::Identity(n, n);
                G.block(i - 1, i - 1, 2, 2) = GivensRotation(R(i - 1, j), R(i, j));
                R = G * R;
                Q = Q * G.transpose();
            }
        }

        A = R * Q;

        finish = true;
        for (Eigen::Index i = 0; i + 1 < n; ++i) {
            if (!IsCloseToZero(A(i, i + 1))) {
                finish = false;
                break;
            }
        }
    }

    return A.diagonal();
}

Eigen::VectorXd HessenbergQR(const Eigen::MatrixXd& A) {
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("The matrix must be square");
    }

    Eigen::MatrixXd H = GetHessenbergForm(A);
    Eigen::Index n = H.rows();
    bool finish = false;
    while (!finish) {
        std::vector<Eigen::Matrix2d> G(n - 1);
        for (Eigen::Index k = 0; k < n - 1; ++k) {
            G[k] = GivensRotation(H(k, k), H(k + 1, k));
            H.block(k, k, 2, n - k) = G[k] * H.block(k, k, 2, n - k);
        }

        for (Eigen::Index k = 0; k < n - 1; ++k) {
            H.block(0, k, k + 2, 2) = H.block(0, k, k + 2, 2) * G[k].transpose();
        }

        finish = true;
        for (Eigen::Index i = 0; i + 1 < n; ++i) {
            if (!IsCloseToZero(H(i, i + 1))) {
                finish = false;
                break;
            }
        }
    }

    return H.diagonal();
}
} // namespace NLA
