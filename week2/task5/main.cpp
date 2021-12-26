#include <vector>
#include <string>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination) {
    for (auto str: source) destination.push_back(str);
    source.clear();
}