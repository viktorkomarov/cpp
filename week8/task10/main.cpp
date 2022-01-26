#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>

std::set<int>::const_iterator FindNearestElement(const std::set<int>& numbers, int border)
{
    auto lower = numbers.lower_bound(border);

    if (lower == cbegin(numbers) || *lower == border) return lower;
    auto prevLower = std::prev(lower);

    if (std::abs(*prevLower - border) <= std::abs(*lower - border)) {
        return prevLower;
    }

    return lower;
}

// int main() {
//   std::set<int> numbers = {1, 4, 6};
//   std::cout <<
//       *FindNearestElement(numbers, 0) << " " <<
//       *FindNearestElement(numbers, 3) << " " <<
//       *FindNearestElement(numbers, 5) << " " <<
//       *FindNearestElement(numbers, 6) << " " <<
//       *FindNearestElement(numbers, 100) << std::endl;
      
//   std::set<int> empty_set;
  
//   std::cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << std::endl;
//   return 0;
// }