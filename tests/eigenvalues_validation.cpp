#include "eigenvalues_validation.h"
#include "../tools.h"

namespace NLA {
bool IsEigenvaluesCorrect(Vector eigenvalues, const Matrix& A) {
    Index n = A.rows();

    Eigen::VectorXcd complex_correct = A.eigenvalues();
    Vector correct(n);
    for (Index i = 0; i < n; ++i) {
        correct(i) = complex_correct(i).real();
    }

    std::sort(eigenvalues.begin(), eigenvalues.end());
    std::sort(correct.begin(), correct.end());

    for (Index i = 0; i < n; ++i) {
        if (abs(eigenvalues(i) - correct(i)) >= EPS) {
            return false;
        }
    }

    return true;
}
} // namespace NLA
