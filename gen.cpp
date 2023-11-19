#include <iostream>
#include <random>

constexpr int MOD = 1e9;

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "You gave wrong amount of arguments!";
        return 404;
    }

    const int seed = atoi(argv[1]);
    std::mt19937 rng(seed);
    int n = (((rng() % MOD) + MOD) % MOD) + 1;

    std::cout << n << std::endl;
    for (int i = 0; i < n; i++) {
        int num = (((rng() % MOD) + MOD) % MOD) + 1;
        if ((rng() % 2)) {
            num *= -1;
        }
        std::cout << num << ' ';
    }

    std::cout << std::endl;
    return 0;
}