#include <iostream>
#include <map>
#include <vector>
#include <string>

void print(std::map<std::string, std::vector<std::string>> map) {
    for (const auto& [key, values] : map) {
        std::cout << key;
        for (const auto& value : values) {
            std::cout << " " << value;
        }
        std::cout << "\n";
    }
}

int main() {
    int q;
    std::cin >> q;
    
    std::map<std::string, std::vector<std::string>> bus_to_stops;
    std::map<std::string, std::vector<std::string>> stop_to_buses;

    while (q--) {
        std::string command;
        std::cin >> command;

        if (command == "NEW_BUS") {
            std::string bus;
            int stop_count;
            
            std::cin >> bus >> stop_count;
            std::vector<std::string> stops(stop_count);
            for (auto& stop : stops) {
                std::cin >> stop;
                stop_to_buses[stop].emplace_back(bus);
            }
            bus_to_stops[bus] = std::move(stops);

        } else if (command == "BUSES_FOR_STOP") {
            std::string stop;
            std::cin >> stop;

            auto it = stop_to_buses.find(stop);
            if (it == stop_to_buses.cend()) {
                std::cout << "No stop\n";
            } else {
                for (const auto& bus : it->second) {
                    std::cout << bus << " ";
                }
                std::cout << "\n";
            }
        } else if (command == "STOPS_FOR_BUS") {
            std::string bus;
            std::cin >> bus;

            auto it = bus_to_stops.find(bus);
            if (it == bus_to_stops.cend()) {
                std::cout << "No bus\n";
                continue;
            }
            for (const auto& stop : bus_to_stops[bus]) {
                std::cout << "Stop " << stop << ":";
                const auto& buses = stop_to_buses[stop];
                if (buses.size() == 1) {
                    std::cout << " no interchange\n";
                    continue;
                }
                for (const auto& buss : buses) {
                    if (bus != buss) {
                        std::cout << " " << buss;
                    }
                }
                std::cout << "\n";
            }
        } else if (command == "ALL_BUSES") {
            if (bus_to_stops.size() == 0) {
                std::cout << "No buses\n";
                continue;
            }
            for (const auto& [bus, stops] : bus_to_stops) {
                std::cout << "Bus " << bus << ":";
                for (const auto& stop : stops) {
                    std::cout << " " << stop;
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}