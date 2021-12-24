#include <iostream>

int nod(int a, int b) {
    return (a % b  == 0) ?  b : nod(b, a%b);
}

int main(){
    int a, b;
    std::cin >> a >> b;

    std::cout << nod(std::max(a, b),std::min(a, b)) << std::endl;
}