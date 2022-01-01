#include <fstream>
#include <iomanip>
#include <iostream>

int main(){
    std::ifstream from("input.txt");
    std::cout.precision(3);
    std::cout << std::fixed;
    double d;
    while(from >> d){
        std::cout << d << std::endl;
    }
}