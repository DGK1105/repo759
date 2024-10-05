#include "matmul.h"

// mmul1: Standard matrix multiplication (i, j, k) order
void mmul1(const double* A, const double* B, double* C, const unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            C[i * n + j] = 0.0;
            for (unsigned int k = 0; k < n; ++k) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

// mmul2: Swapping the two innermost loops (i, k, j) order
void mmul2(const double* A, const double* B, double* C, const unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int k = 0; k < n; ++k) {
            for (unsigned int j = 0; j < n; ++j) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

// mmul3: Moving the outermost loop to the innermost position (j, i, k) order
void mmul3(const double* A, const double* B, double* C, const unsigned int n) {
    for (unsigned int j = 0; j < n; ++j) {
        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int k = 0; k < n; ++k) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

// mmul4: Using std::vector and implementing the same order as mmul1
void mmul4(const std::vector<double>& A, const std::vector<double>& B, double* C, const unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            C[i * n + j] = 0.0;
            for (unsigned int k = 0; k < n; ++k) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

