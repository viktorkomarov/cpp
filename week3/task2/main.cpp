#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> v(n);
    for(auto& x : v) std::cin >> x;

    std::sort(begin(v), end(v), [](const std::string& x, const std::string& y) {
        std::vector<char> x_vec;
        for (const auto c : x) x_vec.push_back(std::tolower(c));

        std::vector<char> y_vec;
        for (const auto c : y) y_vec.push_back(std::tolower(c));

        return x_vec < y_vec;
    });

    for(const auto& x : v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}