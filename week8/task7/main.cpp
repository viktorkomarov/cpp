#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename IteratorIt>
void PrintRange(IteratorIt from, IteratorIt to)
{
    for(;from != to; from = std::next(from))
    {
        std::cout << *from << " ";
    }
    std::cout << std::endl;
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if(range_end - range_begin < 2) return;
    
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto mid = std::next(begin(elements), elements.size() / 2);
    MergeSort(begin(elements), mid);
    MergeSort(mid, end(elements));
    
    std::merge(begin(elements), mid, mid, end(elements), range_begin);
}

// int main() {
//   std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
//   MergeSort(begin(v), end(v));
//   for (int x : v) {
//     std::cout << x << " ";
//   }
//   std::cout << std::endl;
//   return 0;
// }
