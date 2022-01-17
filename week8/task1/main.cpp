#include <vector>
#include <algorithm>
#include <iostream>


void PrintVectorPart(const std::vector<int>& numbers)
{
    auto it = std::find_if(begin(numbers), end(numbers), [](const int& num)->bool{
        return num < 0;
    });

    while (it != begin(numbers))
    {
        --it;
        std::cout << *it << " ";
    }
}

// int main()
// {
//   PrintVectorPart({6, 1, 8, -5, 4});
//   std::cout << std::endl;
//   PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
//   std::cout << std::endl;
//   PrintVectorPart({6, 1, 8, 5, 4});
//   std::cout << std::endl;
//   return 0;
// }