#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border)
{
    auto it = std::find_if(begin(elements), end(elements), [border](const T& item)->bool{
        return item > border;
    });

    std::vector<T> result(it, end(elements));
    return result;
}

int main() {
  for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  
  std::string to_find = "Python";
  std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
  return 0;
}
