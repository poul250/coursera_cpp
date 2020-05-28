#include <vector>
#include <string>

using words = std::vector<std::string>;

void MoveStrings(words& src, words& dst) {
    for (const auto& word : src) {
        dst.emplace_back(word);
    }
    src.clear();
}