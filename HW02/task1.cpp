#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "scan.h"

int main() {
    // Set seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number n between 1024 and 1048576
    std::size_t n = 1024 + std::rand() % (1048576 - 1024 + 1);

    // Create an array of n random float numbers between -1.0 and 1.0
    float *arr = new float[n];
    for (std::size_t i = 0; i < n; ++i) {
        arr[i] = static_cast<float>(std::rand()) / RAND_MAX * 2.0f - 1.0f;
    }

    // Create output array
    float *output = new float[n];

    // Scan the array and measure the time taken
    auto start = std::chrono::high_resolution_clock::now();
    scan(arr, output, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    // Print the time taken
    std::cout << duration.count() << std::endl;

    // Print the first and last elements of the output scanned array
    if (n > 0) {
        std::cout << output[0] << std::endl;
        std::cout << output[n - 1] << std::endl;
    }

    // Deallocate memory
    delete[] arr;
    delete[] output;

    return 0;
}

