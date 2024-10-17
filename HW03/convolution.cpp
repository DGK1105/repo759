#include "convolution.h"
#include <vector>
#include <omp.h>

std::vector<float> convolve(const float *f, const float *w, int n, int m) {
    int half_m = m / 2;
    std::vector<float> g(n * n, 0.0f);
#pragma omp parallel for collapse(2) schedule(static)
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            float sum = 0.0f;
            
            // Perform convolution for the (x, y) element
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    int x_idx = x + i - half_m;
                    int y_idx = y + j - half_m;

                    // Handle boundary conditions
                    float f_value = 0.0f;
                    if (x_idx >= 0 && x_idx < n && y_idx >= 0 && y_idx < n) {
                        f_value = f[x_idx * n + y_idx];
                    } else if ((x_idx >= 0 && x_idx < n) || (y_idx >= 0 && y_idx < n)) {
                        f_value = 1.0f;
                    }

                    sum += w[i * m + j] * f_value;
                }
            }
            g[x * n + y] = sum;
        }
    }

    return g;
}
