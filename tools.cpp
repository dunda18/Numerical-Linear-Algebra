#include "tools.h"

#include <cmath>

namespace NLA {
bool IsCloseToZero(double val) {
    return fabs(val) < EPS;
}

bool IsUpperTriangular(const Matrix& A) {
    for (Index i = 0; i < A.rows(); ++i) {
        for (Index j = i + 1; j < A.cols(); ++j) {
            if (!IsCloseToZero(A(i, j))) {
                return false;
            }
        }
    }

    return true;
}

bool IsHessenbergUpperTriangular(const Matrix& H) {
    for (Index i = 0; i + 1 < H.rows(); ++i) {
        if (!IsCloseToZero(H(i, i + 1))) {
            return false;
        }
    }

    return true;
}
} // namespace NLA
