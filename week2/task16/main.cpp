#include <set>
#include <map>
#include <string>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> set;
    for(const auto& pair : m) set.insert(pair.second);
    return set;
}