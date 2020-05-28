#include <iostream>
#include <map>
#include <set>
#include <string>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> result;
    for (const auto& [key, value] : m) {
        result.emplace(value);
    }

    return result;
}
