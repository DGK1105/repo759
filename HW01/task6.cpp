#include <iostream>
#include <cstdio> // For printf

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./task6 N" << std::endl;
        return 1;
    }

    int N = std::stoi(argv[1]);

    for (int i = 0; i <= N; ++i) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = N; i >= 0; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

