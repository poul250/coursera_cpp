#include <iostream>
#include <map>
#include <string>

template<typename Container, typename Key>
bool contains(const Container& container, const Key& key) {
    return container.find(key) != container.cend();
}

int main() {
    std::map<std::string, std::string> capitals;

    int q;
    std::cin >> q;
    while (q--) {
        std::string command;
        std::cin >> command;

        if (command == "CHANGE_CAPITAL") {
            std::string country, capital;
            std::cin >> country >> capital;

            if (!contains(capitals, country)) {
                std::cout << "Introduce new country "
                          << country
                          << " with capital "
                          << capital
                          << "\n";
            } else if (capitals[country] == capital) {
                std::cout << "Country "
                          << country
                          << " hasn't changed its capital\n";
            } else {
                std::cout << "Country "
                          << country
                          << " has changed its capital from "
                          << capitals[country]
                          << " to "
                          << capital
                          << "\n";
            }

            capitals[country] = capital;
        } else if (command == "RENAME") {
            std::string name, new_name;
            std::cin >> name >> new_name;

            if (name == new_name || 
                    !contains(capitals, name) ||
                    contains(capitals, new_name)) {
                std::cout << "Incorrect rename, skip\n";
            } else {
                auto capital = capitals[name];
                capitals.erase(name);
                capitals[new_name] = capital;
                std::cout << "Country "
                          << name 
                          << " with capital "
                          << capital 
                          << " has been renamed to "
                          << new_name
                          << '\n';
            }
        } else if (command == "ABOUT") {
            std::string country;
            std::cin >> country;

            if (!contains(capitals, country)) {
                std::cout << "Country " << country << " doesn't exist\n";
            } else {
                std::cout << "Country " 
                          << country 
                          << " has capital " 
                          << capitals[country]
                          << '\n';
            }
        } else if (command == "DUMP") {
            if (capitals.size() == 0) {
                std::cout << "There are no countries in the world\n";
            } else {
                bool first_time = true;
                for (const auto& [country, capital] : capitals) {
                    if (!first_time) std::cout << " ";
                    first_time = false;
                    std::cout << country << "/" << capital;
                }
                std::cout << "\n";
            }
        }
    }
}