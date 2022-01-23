#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <sstream>
#include <map>

struct ExprAlgebra{
    int number = 0;
    char op = '\0';
    char prev_op = '\0';
};

const std::map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'\0', 3}};

int main()
{
    std::vector<ExprAlgebra> exprs;
    int init;
    std::cin >> init;

    int q;
    char prev_op = '\0';
    std::cin >> q;
    while (q--)
    {

        char op;
        int num;
        std::cin >> op >> num;
        exprs.push_back({num, op, prev_op});
        prev_op = op;
    }

    std::cout << std::accumulate(begin(exprs), end(exprs), std::to_string(init), [](const std::string& acc, const ExprAlgebra& elem){
        std::stringstream ss;
        if (priority.at(elem.op) > priority.at(elem.prev_op)) {
            ss << "(" << acc << ")" << " " << elem.op << " " << std::to_string(elem.number);
        } else {
            ss << acc << " " << elem.op << " " << std::to_string(elem.number);
        }

        return ss.str();
    }) << std::endl;

    return 0;   
}