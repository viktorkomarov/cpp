#include <iostream>
#include <set>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, std::set<std::string>> synons;
    while (n--)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "ADD") {
            std::string word1, word2;
            std::cin >> word1 >> word2;

            synons[word1].insert(word2);
            synons[word2].insert(word1);
        } else if (cmd == "COUNT") {
            std::string word;
            std::cin >> word;

            std::cout << synons[word].size() << std::endl;
        } else if (cmd == "CHECK") {
            std::string word1, word2;
            std::cin >> word1 >> word2;

            if (synons[word2].count(word1)) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    
    return 0;
}