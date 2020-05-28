#include <cmath>
#include <iostream>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a == 0) {
        if (b != 0) {
            std::cout << -c / b;
        }
    } else {
        double d = b * b - 4 * a * c;
        if (d == 0) {
            std::cout << -b / (2 * a);
        } else if (d > 0) {
            std::cout << ((-b + std::sqrt(d)) / (2 * a))
                      << ' '
                      << ((-b - std::sqrt(d)) / (2 * a));
        }
    }

    return 0;
}