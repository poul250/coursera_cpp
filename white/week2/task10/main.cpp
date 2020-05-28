#include <vector>
#include <iostream>

static const std::vector days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void next_month(int& month) {
    month = (month + 1) % days_in_month.size();
}

void print_plans(const std::vector<std::string> plans) {
    std::cout << plans.size();
    for (const auto& plan : plans) {
        std::cout << ' ' << plan;
    }
    std::cout << '\n';
}

int main() {
    int month = 0;
    std::vector<std::vector<std::string>> plans(days_in_month[month]);
    
    int q;
    std::cin >> q;
    while (q--) {
        std::string command;
        std::cin >> command;

        if (command == "ADD") {
            int i;
            std::string s;
            std::cin >> i >> s;

            plans[i-1].emplace_back(s);
        } else if (command == "DUMP") {
            int i;
            std::cin >> i;
            print_plans(plans[i-1]);
        } else if (command == "NEXT") {
            int last_days = days_in_month[month];
            next_month(month);
            int days = days_in_month[month];
    
            for (int i = days; i < last_days; ++i) {
                plans[days-1].insert(
                    plans[days-1].end(), plans[i].begin(), plans[i].end());
            }
            plans.resize(days, {});
        }
    }

    return 0;
}