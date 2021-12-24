#include <iostream>
#include <string>

int main() {
    using std::string;

    string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::min(c, std::min(a,b));
}