#include <iostream>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::set<std::string> set;
    while (n--)
    {
        std::string str;
        std::cin >> str;
        set.insert(str);
    }
    
    std::cout << set.size() << std::endl;
    return 0;
}