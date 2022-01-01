#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream input("input.txt");
    if (input) {
        int strings = 0, rows = 0;
        input >> strings >> rows;
        int number;
        for (int i = 0; i < strings; i++) {
            for (int j = 0; j < rows; j++) {
                input >> number;
                std::cout << std::setw(10) << number;
                if (j != rows - 1) {
                    std::cout << " ";
                }
                input.ignore(1);
            }
            if (i != strings - 1) {
                std::cout << "\n";
            }
        }
        while (input >> number) {

        }
    }

    return 0;
}