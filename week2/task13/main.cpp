#include <map>
#include <vector>
#include <string>
#include <iostream>


void print_bus(const std::vector<std::string>& buses, const std::string& except) {
    for (const auto& str : buses) {
        if (str != except) std::cout << str << " ";
    }
    std::cout << std::endl;
}

int main() {
    using std::string;
    int n;
    std::cin >> n;

    std::map<string, std::vector<string>> buses;
    std::map<string, std::vector<string>> buses_by_stops;
    while (n--)
    {
        string cmd;
        std::cin >> cmd;
        
        if (cmd == "NEW_BUS") {
            string bus;
            int stop_count;
            std::cin >> bus >> stop_count;

            std::vector<string> stops(stop_count);
            for(auto& stop : stops) {
                std::cin >> stop;
                buses_by_stops[stop].push_back(bus);
            }
            buses[bus] = stops;
        } else if (cmd == "BUSES_FOR_STOP") {
            string stop;
            std::cin >> stop;

            if (buses_by_stops.count(stop) == 0) {
                std::cout << "No stop" << std::endl;
            } else {
                print_bus(buses_by_stops[stop], "");
            }
        } else if (cmd == "STOPS_FOR_BUS") {
            string bus;
            std::cin >> bus;

            if (buses.count(bus) == 0) {
                std::cout << "No bus" << std::endl;
            } else {
                for (const auto& stop : buses[bus]) {
                    std::cout << "Stop " << stop << ": ";
                    if (buses_by_stops[stop].size() == 1) {
                        std::cout << "no interchange" << std::endl;
                    } else {
                        print_bus(buses_by_stops[stop], bus);
                    }
                }
            }
        } else if (cmd == "ALL_BUSES") {
            if (buses.empty()) {
                std::cout << "No buses" << std::endl;
            } else {
                for (const auto& bus : buses) {
                    std::cout << "Bus " << bus.first << ":";
                    for(const auto& stop : bus.second) {
                        std::cout << " " << stop;
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
    
    return 0;
}