#include <iostream>
#include <set>

int main() {
    int q;
    std::cin >> q;
    std::set<std::string> strings;
    while (q--) {
        std::string str;
        std::cin >> str;
        strings.insert(str);
    }
    std::cout << strings.size();
}