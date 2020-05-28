#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (auto& word : words) {
        std::cin >> word;
    }

    std::sort(words.begin(), words.end(), [](const std::string& left, const std::string& right) -> bool{
        int size = std::min(left.size(), right.size());

        for (int i = 0; i < size; ++i) {
            if (std::tolower(left[i]) < std::tolower(right[i])) return true;
            if (std::tolower(left[i]) > std::tolower(right[i])) return false;
        }

        return left.size() <= right.size();
    });

    for (const auto& word : words) {
        std::cout << word << " ";
    }

    return 0;
}