#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int q;
    std::cin >> q;

    std::map<std::set<std::string>, int> rases;

    while (q--) {
        int rases_count;
        std::cin >> rases_count;

        std::set<std::string> stops;
        while (rases_count--) {
            std::string stop;
            std::cin >> stop;

            stops.insert(stop);
        }

        auto it = rases.find(stops);

        if (it != rases.cend()) {
            std::cout << "Already exists for " << it->second << "\n";
        } else {
            int new_rase = rases.size() + 1;
            rases[stops] = new_rase;
            std::cout << "New bus " << new_rase << "\n";
        }
    }
    return 0;
}