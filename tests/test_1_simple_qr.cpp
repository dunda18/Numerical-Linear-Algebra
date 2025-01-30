#include "test_1_simple_qr.h"
#include "../tools.h"
#include "../eigen_solver.h"

void Test1SimpleQR() {
    for (int _ = 0; _ < 100; ++_) {
        Eigen::Index n = rand() % 10 + 1;
        Eigen::MatrixXd A = Eigen::MatrixXd::Random(n, n);
        for (Eigen::Index i = 0; i < n; ++i) {
            for (Eigen::Index j = i; j < n; ++j) {
                A(i, j) = A(j, i);
            }
        }

        Eigen::VectorXd eigenvalues = NLA::SimpleQR(A);
        Eigen::VectorXcd complex_correct = A.eigenvalues();
        Eigen::VectorXd correct(n);
        for (Eigen::Index i = 0; i < n; ++i) {
            correct(i) = complex_correct(i).real();
        }
        std::sort(eigenvalues.begin(), eigenvalues.end());
        std::sort(correct.begin(), correct.end());
        for (Eigen::Index i = 0; i < n; ++i) {
            assert(abs(eigenvalues(i) - correct(i)) < NLA::EPS);
        }
    }
}
