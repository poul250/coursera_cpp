#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (auto& num : nums) {
        std::cin >> num;
    }

    std::sort(nums.begin(), nums.end(), [](int left, int right) {
        return std::abs(left) <= std::abs(right);
    });

    for (auto num : nums) {
        std::cout << num << " ";
    }

    return 0;
}