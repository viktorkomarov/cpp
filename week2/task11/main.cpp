#include <map>
#include <iostream>

std::map<char, int> build_anagram(std::string str) {
    std::map<char, int> anagram;
    for(auto c : str) ++anagram[c];
    return anagram;
}

int main() {
    int n;
    std::cin >> n;

    while (n--)
    {
        std::string a,b;
        std::cin >> a >> b;

        if (build_anagram(a) == build_anagram(b)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}