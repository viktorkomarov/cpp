#include <fstream>
#include <string>
#include <iostream>

int main(){
    std::ifstream from("input.txt");
    std::ofstream to("output.txt");
    std::string str;
    while (std::getline(from, str))
    {
       to << str << '\n';
    }
}