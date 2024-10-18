#include "msort.h"
#include <algorithm> // For std::sort
#include <cstring>   // For memcpy

// Helper function to merge two sorted halves of the array
void merge(int* arr, int* temp, std::size_t left, std::size_t mid, std::size_t right) {
    std::size_t i = left, j = mid, k = left;

    // Merge elements from both halves into temp array
    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy any remaining elements from the left half
    while (i < mid) {
        temp[k++] = arr[i++];
    }

    // Copy any remaining elements from the right half
    while (j < right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    std::memcpy(arr + left, temp + left, (right - left) * sizeof(int));
}

// Parallel merge sort implementation
void parallel_merge_sort(int* arr, int* temp, std::size_t left, std::size_t right, std::size_t threshold) {
    if (right - left <= threshold) {
        // Use serial sort when the size is below the threshold
        std::sort(arr + left, arr + right);
        return;
    }

    std::size_t mid = left + (right - left) / 2;

    // Sort the two halves in parallel using OpenMP
    #pragma omp parallel sections
    {
        #pragma omp section
        parallel_merge_sort(arr, temp, left, mid, threshold);

        #pragma omp section
        parallel_merge_sort(arr, temp, mid, right, threshold);
    }
// Merge the two sorted halves
    merge(arr, temp, left, mid, right);
}

// Wrapper function matching the signature in msort.h
void msort(int* arr, const std::size_t n, const std::size_t threshold) {
    // Allocate a temporary array for merging
    int* temp = new int[n];

    // Call the parallel merge sort function
    parallel_merge_sort(arr, temp, 0, n, threshold);

    // Free the temporary array
    delete[] temp;
}
