#include "scan.h"

std::vector<float> inclusive_scan(const std::vector<float>& input) {
    std::vector<float> result(input.size());
    if (input.empty()) return result;

    result[0] = input[0];
    for (size_t i = 1; i < input.size(); ++i) {
        result[i] = result[i - 1] + input[i];
    }
    return result;
}

