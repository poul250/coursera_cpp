#include <vector>

std::vector<int> Reversed(const std::vector<int> numbers) {
    std::vector<int> result;
    for (int i = numbers.size() - 1; i >= 0; --i) {
        result.push_back(numbers[i]);
    }
    return result;
}