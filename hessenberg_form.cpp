#include "hessenberg_form.h"
#include "householder_reflection.h"

namespace NLA {
Matrix GetHessenbergForm(Matrix A) {
    assert(A.rows() == A.cols());

    if (A.rows() < 3) {
        return A;
    }

    Index n = A.rows();
    std::vector<Vector> u(n - 2);
    for (Index k = 0; k < n - 2; ++k) {
        Vector x = A.col(k).tail(n - k - 1);

        u[k] = HouseholderVector(x);

        A.bottomRightCorner(n - k - 1, n - k) -= 2 * u[k] * (u[k].transpose() * A.bottomRightCorner(n - k - 1, n - k));

        A.bottomRightCorner(n, n - k - 1) -= 2 * (A.bottomRightCorner(n, n - k - 1) * u[k]) * u[k].transpose();
    }

    return A;
}
} // namespace NLA
