#include "convolution.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " n m" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);

    if (m % 2 == 0) {
        std::cerr << "Error: m must be an odd number." << std::endl;
        return 1;
    }

    // Create n x n image matrix (stored in 1D in row-major order)
    std::vector<float> image(n * n);
    std::srand(std::time(nullptr));
    for (int i = 0; i < n * n; ++i) {
        image[i] = static_cast<float>(std::rand()) / RAND_MAX * 20.0f - 10.0f; // Random float between -10.0 and 10.0
    }

    // Create m x m mask matrix (stored in 1D in row-major order)
    std::vector<float> mask(m * m);
    for (int i = 0; i < m * m; ++i) {
        mask[i] = static_cast<float>(std::rand()) / RAND_MAX * 2.0f - 1.0f; // Random float between -1.0 and 1.0
    }

    // Apply the mask to the image using the convolve function and measure the time taken
    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> convolved = convolve(image.data(), mask.data(), n, m);
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate and print the time taken in milliseconds
    std::chrono::duration<double, std::milli> elapsed_time = end_time - start_time;
    std::cout << elapsed_time.count() << std::endl;

    // Print the first and last elements of the resulting convolved array
    std::cout << convolved[0] << std::endl;
    std::cout << convolved[n * n - 1] << std::endl;

    return 0;
}

