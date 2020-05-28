#include <iostream>
#include <vector>

int main() {
    std::vector<bool> peoples;

    int commands_count;
    std::cin >> commands_count;
    while (commands_count--) {
        std::string command;
        std::cin >> command;

        if (command == "WORRY" || command == "QUIET") {
            int i;
            std::cin >> i;
            peoples[i] = command == "WORRY";
        } else if (command == "COME") {
            int num;
            std::cin >> num;
            peoples.resize(peoples.size() + num);
        } else {
            int worries = 0;
            for (auto worry : peoples) {
                worries += worry;
            }
            
            std::cout << worries << '\n';
        }
    }
    return 0;
}