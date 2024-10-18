#include <iostream>
#include <cstdlib>
#include <chrono> // For measuring time
#include "msort.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./task3 <n> <t> <ts>\\n";
        return 1;
    }

    // Parse command line arguments
    std::size_t n = std::stoul(argv[1]);  // Length of the array
    int t = std::stoi(argv[2]);           // Number of threads
    std::size_t ts = std::stoul(argv[3]); // Threshold for serial sort

    // Set the number of threads for OpenMP
    omp_set_num_threads(t);

    // Allocate and fill the array with random numbers in the range [-1000, 1000]
    int* arr = new int[n];
    for (std::size_t i = 0; i < n; ++i) {
        arr[i] = rand() % 2001 - 1000; // Random number between -1000 and 1000
    }

    // Measure the time taken by the msort function
    auto start = std::chrono::high_resolution_clock::now();
    msort(arr, n, ts);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Print the first and last elements of the sorted array
    std::cout << "First element: " << arr[0] << "\n";
    std::cout << "Last element: " << arr[n - 1] << "\n";
    std::cout << "Time taken: " << duration.count() << " ms\n";

    // Free the allocated memory
    delete[] arr;

    return 0;
}
