#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <tuple>

enum class Lang {
  DE, FR, IT
};

struct Region {
  std::string std_name;
  std::string parent_std_name;
  std::map<Lang, std::string> names;
  int64_t population;
};


bool operator==(const Region& lhs, const Region& rhs) {
    return 
        std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) 
         ==
        std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

bool operator<(const Region& lhs, const Region& rhs) {
    return 
        std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) 
         <
        std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const std::vector<Region>& regions) {
    std::map<Region, int> max;
    for (const auto& region : regions) {
        ++max[region];
    }
    int result = 0;
    for(auto& item : max) {
        if (item.second > result) result = item.second;
    }
    return result;
}
