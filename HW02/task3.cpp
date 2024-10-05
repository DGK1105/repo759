#include "matmul.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <matrix_size>" << std::endl;
        return 1;
    }

    unsigned int n = std::stoi(argv[1]);

    // Generate matrices A and B with random values
    std::vector<double> A(n * n);
    std::vector<double> B(n * n);
    std::vector<double> C(n * n, 0.0);

    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> dis(-10.0, 10.0);

    for (unsigned int i = 0; i < n * n; ++i) {
        A[i] = dis(gen);
        B[i] = dis(gen);
    }

    // Run matrix multiplication with each function and measure the time
    auto start = std::chrono::high_resolution_clock::now();
    mmul1(A.data(), B.data(), C.data(), n);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << n << std::endl;
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mmul2(A.data(), B.data(), C.data(), n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mmul3(A.data(), B.data(), C.data(), n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mmul4(A, B, C.data(), n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    return 0;
}

