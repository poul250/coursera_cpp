#include <iostream>
#include <vector>
#include <map>

int main() {
    int q;
    std::cin >> q;

    std::map<std::vector<std::string>, int> stops_to_num;

    while (q--) {
        int stops_count;
        std::cin >> stops_count;
        std::vector<std::string> stops;
        stops.reserve(stops_count);

        for (int i = 0; i < stops_count; ++i) {
            std::string stop;
            std::cin >> stop;
            stops.emplace_back(std::move(stop));
        }

        auto it = stops_to_num.find(stops);
        if (it != stops_to_num.cend()) {
            std::cout << "Already exists for " << it->second << "\n";
        } else {
            auto size = stops_to_num.size();
            stops_to_num[stops] = size + 1;
            std::cout << "New bus " << size + 1 << "\n";  
        }
    }

    return 0;
}