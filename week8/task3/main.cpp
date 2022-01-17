#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<std::string> SplitIntoWords(const std::string& s)
{
    std::vector<std::string> result;

    auto from = begin(s);
    while (true)
    {
        auto it = std::find(from, end(s), ' ');
        if (it == end(s)) {
          result.push_back(std::string(from, it));
          return result;
        }
        result.push_back(std::string(from, it));
        from = std::next(it);
    }    
}

// int main() {
//   std::string s = "C Cpp Java Python";

//   std::vector<std::string> words = SplitIntoWords(s);
//   std::cout << words.size() << " ";
//   for (auto it = begin(words); it != end(words); ++it) {
//     if (it != begin(words)) {
//       std::cout << "/";
//     }
//     std::cout << *it;
//   }
//   std::cout << std::endl;
  
//   return 0;
// }