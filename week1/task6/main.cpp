#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            std::cout << i;
            if (i != b) {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
}