#include <iostream>
#include <set>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<std::set<std::string>, int> buses;
    while (n--)
    {
        int count;
        std::cin >> count;
        
        std::set<std::string> stops;
        for(int i = 0; i < count; ++i){
            std::string stop;
            std::cin >> stop;

            stops.insert(stop);
        }

        if (buses.count(stops) == 0) {
            int number = buses.size() + 1;
            buses[stops] = number;
            std::cout << "New bus " << number << std::endl;
        } else {
            std::cout <<  "Already exists for " << buses[stops] << std::endl;
        }
    }
    
    return 0;
}