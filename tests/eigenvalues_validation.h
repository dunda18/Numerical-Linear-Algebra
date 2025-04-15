#ifndef NUMERICAL_LINEAR_ALGEBRA_EIGENVALUES_VALIDATION_H
#define NUMERICAL_LINEAR_ALGEBRA_EIGENVALUES_VALIDATION_H

#include "../linalg.h"

namespace NLA {
bool IsEigenvaluesCorrect(Vector eigenvalues, const Matrix& A);
} // namespace NLA

#endif //NUMERICAL_LINEAR_ALGEBRA_EIGENVALUES_VALIDATION_H
