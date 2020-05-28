#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int mean = 0;
    std::vector<int> nums(n);
    for (auto& num : nums) {
        int value;
        std::cin >> value;
        
        mean += value;
        num = value;
    }

    mean /= n;

    std::vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > mean) {
            result.push_back(i);
        }
    }
    
    std::cout << result.size() << '\n';
    for (auto day : result) {
        std::cout << day << ' ';
    }

    return 0;
}