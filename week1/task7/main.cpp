#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    int second_idx = -2;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'f') {
            if (second_idx == -1) {
                second_idx = i;
            } else if (second_idx < 0) {
                second_idx++;
            }
        }
    }

    std::cout << second_idx << std::endl;
    return 0;
}