#include <map>
#include <iostream>

std::map<char, int> BuildCharCounters(const std::string& str) {
    std::map<char, int> result;
    for (auto ch : str) {
        result[ch] += 1;
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        std::string first, second;
        std::cin >> first >> second;

        if (BuildCharCounters(first) == BuildCharCounters(second)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}