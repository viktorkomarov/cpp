#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

int main() {
    int k;
    std::cin >> k;
    std::vector<std::int64_t> temps(k);

    std::int64_t sum = 0;
    for(auto& t : temps) {
        std::cin >> t;
        sum += t;
    }

    std::int64_t avg = (sum / static_cast<std::int64_t>(temps.size()));
    std::int64_t count = std::count_if(begin(temps), end(temps), [avg](std::int64_t val)->bool{
        return val > avg;
    });
    std::cout << count << std::endl;
    std::vector<std::int64_t> upper;
     for(size_t i = 0; i < temps.size(); ++i) if (temps[i] > avg) upper.push_back(i);
    for(size_t i = 0; i < upper.size(); ++i) {
        std::cout << upper[i];
        if(i + 1 < upper.size()) std::cout << " ";
    }
    std::cout << std::endl;
}