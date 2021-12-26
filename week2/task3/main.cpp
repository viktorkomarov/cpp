#include <vector>
#include <string>

bool IsPalindrom(std::string str) {
    int l = 0,  r = str.size()-1;
    while(l < r) {
        if (str[l] != str[r]) return false;
        ++l;
        --r;
    }
    return true;
}


std::vector<std::string> PalindromFilter( std::vector<std::string> vec,int minLength){
    std::vector<std::string> result;
    for(auto str : vec) {
        if(IsPalindrom(str) && str.size() >= minLength) result.push_back(str);
    }
    return result;
}