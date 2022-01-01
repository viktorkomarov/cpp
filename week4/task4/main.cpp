#include <fstream>
#include <string>
#include <iostream>

int main(){
    std::ifstream from("input.txt");
    std::string str;
   while (std::getline(from, str))
   {
       std::cout << str << '\n';
   }
}