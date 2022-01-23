#include <iostream>
#include <string>
#include <numeric>
#include <deque>
#include <sstream>
#include <algorithm>

int main()
{
    int init;
    std::cin >> init;

    int q;
    std::cin >> q;

    std::deque<std::string> elems;
    elems.push_back(std::to_string(init));
    while (q--)
    {
        int num;
        char op;
        std::cin >> op >> num;
        std::stringstream ss;
        ss << op << " " << std::to_string(num);
     
        elems.push_front("(");
        elems.push_back(") ");
        elems.push_back(ss.str());
    }

    for (const auto& str : elems) std::cout << str;
    std::cout << std::endl;

    return 0;   
}