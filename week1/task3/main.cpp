#include <iostream>
#include <cmath>

int main(){
    double a,b,c;
    std::cin >> a >> b >> c;

    if (a != 0 && b != 0) {
        double d = b * b - 4 * a * c;
        if (d > 0){
            std::cout << (-b - std::sqrt(d)) / (2 * a) << ' ' << (-b + std::sqrt(d)) / (2 * a);
        } else if (d == 0) {
            std::cout << (-b / (2 * a));
        }
    } else if (b != 0 && a == 0) {
        if (c == 0 ) {
            std::cout << 0;
        } else {
            std::cout << -c / b;
        }
    } else if (a != 0 && b == 0) {
        if ((c > 0 && a < 0) || c < 0) {
            std::cout << std::sqrt(-c / a) << ' ' << -std::sqrt(-c / a);
        }else if (c == 0) {
            std::cout << 0;
        }
    }

    return 0;
}