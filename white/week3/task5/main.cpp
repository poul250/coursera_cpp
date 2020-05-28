#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
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

    std::string GetFullNameWithHistory(int year) {
      const auto& first_name = GetHistory(first_names.begin(), first_names.upper_bound(year));
      const auto& last_name = GetHistory(last_names.begin(), last_names.upper_bound(year));

      if (first_name.empty() && last_name.empty()) return "Incognito";
      if (last_name.empty()) return first_name + " with unknown last name";
      if (first_name.empty()) return last_name + " with unknown first name";
      return first_name + " " + last_name;
    }
private:

  template<typename FirstIt, typename SecondIt>
  std::vector<std::string> CreateHistory(FirstIt first, SecondIt second) {
    if (first == second) return {};
    
    std::vector<std::string> result = {first->second};

    for (auto last = first, it = std::next(first); it != second; ++it) {
      if (it->second != last->second) {
        result.emplace_back(it->second);
        last = it;
      }
    }

    return result;
  }

  template<typename FirstIt, typename SecondIt>
  std::string GetHistory(FirstIt first, SecondIt second) {
    auto history = CreateHistory(first, second);

    if (history.size() == 0) return "";
    if (history.size() == 1) return history[0];
    if (history.size() == 2) return history[1] + " (" + history[0] + ")";

    const std::string& current_name = history[history.size() - 1];
    std::ostringstream last_names{};
    last_names << history[history.size() - 2];

    for (int i = history.size() - 3; i >= 0; --i) {
      last_names << ", " << history[i];
    }

    return current_name + " (" + last_names.str() + ")";
  }

  std::map<int, std::string> first_names;
  std::map<int, std::string> last_names;
    
};