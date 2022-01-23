#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <sstream>
#include <algorithm>

int main()
{
    int init;
    std::cin >> init;

    int q;
    std::cin >> q;

    std::stringstream ss;
    ss << std::to_string(init);
    while (q--)
    {
        std::stringstream tempstream;
        char op;
        int num;
        std::cin >> op >> num;
        tempstream << "(" << ss.str() << ")" << " " << op << " " << std::to_string(num);
        ss.swap(tempstream);
    }

    std::cout << ss.str() << std::endl;

    return 0;   
}