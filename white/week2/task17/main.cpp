#include <iostream>
#include <map>
#include <set>

int main() {
    std::map<std::string, std::set<std::string>> synonyms;

    int q;
    std::cin >> q;

    while (q--) {
        std::string command;
        std::cin >> command;

        if (command == "ADD") {
            std::string word1, word2;
            std::cin >> word1 >> word2;

            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        } else if (command == "COUNT") {
            std::string word;
            std::cin >> word;

            std::cout << synonyms[word].size() << "\n";
        } else if (command == "CHECK") {
            std::string word1, word2;
            std::cin >> word1 >> word2;

            const auto& syns = synonyms[word1];

            std::cout << (syns.find(word2) != syns.cend() ? "YES\n" : "NO\n");
        }
    }

    return 0;
}