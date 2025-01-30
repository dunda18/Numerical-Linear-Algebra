#include "hessenberg_form.h"

namespace NLA {
Eigen::MatrixXd GetHessenbergForm(Eigen::MatrixXd A) {
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("The matrix must be square");
    }
    if (A.rows() < 3) {
        return A;
    }

    Eigen::Index n = A.rows();
    std::vector<Eigen::VectorXd> u(n - 2);
    for (Eigen::Index k = 0; k < n - 2; ++k) {
        Eigen::VectorXd x = A.col(k).tail(n - k - 1);

        u[k] = x;
        if (x(0) > 0) {
            u[k](0) += x.norm();
        } else {
            u[k](0) -= x.norm();
        }
        u[k].normalize();

        A.bottomRightCorner(n - k - 1, n - k) -= 2 * u[k] * (u[k].transpose() * A.bottomRightCorner(n - k - 1, n - k));

        A.bottomRightCorner(n, n - k - 1) -= 2 * (A.bottomRightCorner(n, n - k - 1) * u[k]) * u[k].transpose();
    }

    return A;
}
} // namespace NLA
