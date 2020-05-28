#include <vector>

void Reverse(std::vector<int>& numbers) {
    for (int i = 0, j = numbers.size() - 1; i < j; ++i, --j) {
        std::swap(numbers[i], numbers[j]);
    }
}