#include "scan.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // For srand() and rand()
#include <ctime>     // For time()
#include <chrono>    // For timing

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " n" << std::endl;
        return 1;
    }

    // Read n from the command line argument
    int n = std::atoi(argv[1]);
    if (n <= 0) {
        std::cerr << "n must be a positive integer." << std::endl;
        return 1;
    }

    // Create an array of n random float numbers between -1.0 and 1.0
    std::vector<float> array(n);
    std::srand(static_cast<unsigned>(std::time(0)));
    for (int i = 0; i < n; ++i) {
        array[i] = static_cast<float>(std::rand()) / RAND_MAX * 2.0f - 1.0f;
    }

    // Time the inclusive scan function
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<float> result = inclusive_scan(array);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;

    // Print the time taken in milliseconds
    std::cout << duration.count() << std::endl;

    // Print the first and last elements of the output scanned array
    if (!result.empty()) {
        std::cout << result[0] << std::endl;
        std::cout << result[result.size() - 1] << std::endl;
    }

    return 0;
}

