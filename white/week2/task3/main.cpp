#include <iostream>
#include <string>
#include <vector>

bool IsPalindrom(std::string str) {
    for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }

    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) {
    std::vector<std::string> result;
    
    for (const auto& word : words) {
        if (IsPalindrom(word) and word.size() >= minLength) {
            result.emplace_back(word);
        }
    }

    return result;
}