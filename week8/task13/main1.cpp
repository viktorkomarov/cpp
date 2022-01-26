#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <sstream>
#include <map>
#include <deque>


const std::map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'\0', 3}};

int main()
{
    int init;
    std::cin >> init;

    int q;
    std::cin >> q;

    char prev_op = '\0';
    std::deque<std::string> elems;
    elems.push_back(std::to_string(init));
    while (q--)
    {
        int num;
        char op;
        std::cin >> op >> num;
        std::stringstream ss;
        ss << op << " " << std::to_string(num);

        if (priority.at(op) > priority.at(prev_op)) {
            elems.push_front("(");
            elems.push_back(") ");
        } else {
            elems.push_back(" ");
        }
         
        elems.push_back(ss.str());
        prev_op = op;
    }

    for (const auto& str : elems) std::cout << str;
    std::cout << std::endl;

    return 0;   
}