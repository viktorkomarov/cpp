#include <vector>

std::vector<int> Reversed(const std::vector<int>& v){
    std::vector<int> res;
    for (int i = v.size()-1; i >= 0; --i) res.push_back(v[i]);
    return res;
}