#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    for (int i = std::log2(n); i >= 0; --i) {
        if (((1 << i) & n) == (1 << i))  {
            std::cout << 1;
        } else {
            std::cout << 0;
        }
    }
    std::cout << std::endl;
}