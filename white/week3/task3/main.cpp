#include <string>
#include <vector>
#include <set>
#include <algorithm>

class SortedStrings {
public:
  void AddString(const std::string& s) {
      strings.push_back(s);
  }

  std::vector<std::string> GetSortedStrings() {
      std::sort(strings.begin(), strings.end());
      return strings;
  }
private:
    std::vector<std::string> strings;
};