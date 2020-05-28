#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names.emplace(year, first_name);
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_names.emplace(year, last_name);
    }
    std::string GetFullName(int year) {
        auto comp = [](const auto& left, const auto& right) {
          return left < right.first;
        };
        auto first_it = std::upper_bound(
            first_names.begin(), first_names.end(), year, comp);
        auto last_it = std::upper_bound(
            last_names.begin(), last_names.end(), year, comp);
        
        if (first_it == first_names.cbegin() && last_it == last_names.cbegin()) {
            return "Incognito";
        } else if (first_it == first_names.cbegin()) {
            return std::prev(last_it)->second + " with unknown first name";
        } else if (last_it == last_names.cbegin()) {
            return std::prev(first_it)->second + " with unknown last name";
        } else {
            return std::prev(first_it)->second + " " + std::prev(last_it)->second;
        }
    }
private:
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
    
};