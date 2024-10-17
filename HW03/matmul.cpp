#include <matmul.h>

// Parallel matrix multiplication function
void mmul(const float* A, const float* B, float* C, const std::size_t n) {

    // Parallelize the loops using OpenMP
    #pragma omp parallel for collapse(2) schedule(static)
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            float sum = 0;
            for (unsigned int k = 0; k < n; ++k) {
                sum += A[i * n + k] * B[k * n + j];
            }
            C[i * n + j] = sum;
        }
    }
}

