#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::min(a, std::min(b, c));
    return 0;
}