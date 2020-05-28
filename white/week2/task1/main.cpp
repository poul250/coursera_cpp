#include <iostream>

int Factorial(int n) {
    if (n <= 0) {
        return 1;
    }

    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::cout << Factorial(n);

    return 0;
}