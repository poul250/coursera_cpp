#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> bits;

    std::cin >> n;

    while (n > 0) {
        bits.push_back(n & 1);
        n >>= 1;
    }

    for (int i = bits.size() - 1; i >= 0; --i) {
        std::cout << bits[i];
    }

    return 0;
}