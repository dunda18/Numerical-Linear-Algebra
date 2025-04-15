#include "test_1_rayleigh_qr.h"
#include "../eigen_solver.h"
#include "eigenvalues_validation.h"

#include <iostream>

namespace NLA {
void Test1RayleighQR() {
    constexpr int N_MATRICES = 20;
    constexpr Index N = 5;

    clock_t time = 0;
    for (int _ = 0; _ < N_MATRICES; ++_) {
        Matrix A = Matrix::Random(N, N);
        for (Index i = 0; i < N; ++i) {
            for (Index j = i; j < N; ++j) {
                A(i, j) = A(j, i);
            }
        }

        clock_t start = clock();
        Vector eigenvalues = RayleighQR(A);
        clock_t end = clock();
        time += end - start;

        assert(IsEigenvaluesCorrect(eigenvalues, A));
    }

    std::cout << "Test1RayleighQR: Matrix size - " << N << ", Number of matrices - " << N_MATRICES << ", Time: "
              << (double) (time) / CLOCKS_PER_SEC << " seconds" << '\n';
}
} // namespace NLA
