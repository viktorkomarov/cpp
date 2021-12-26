#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<std::vector<std::string>, int> buses;
    while (n--)
    {
        int count;
        std::cin >> count;
        
        std::vector<std::string> stops(count);
        for(auto& str : stops) std::cin >> str;

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