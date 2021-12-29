#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(auto& x : v) std::cin >> x;

    std::sort(begin(v), end(v), [](const int& x, const int& y) {
        return std::abs(x) < std::abs(y);
    });

    for(const auto& x : v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}