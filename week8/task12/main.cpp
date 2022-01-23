#include <tuple>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{
    auto lower_it = std::lower_bound(
        range_begin, range_end, prefix,
            [](const std::string& str, const char& prefix){
            return str[0] < prefix;
        });
    
    if (lower_it == range_end || (*lower_it)[0] != prefix) {
        return std::make_pair(lower_it, lower_it);
    }
    
    auto upper_it = std::upper_bound(
        range_begin, range_end, prefix,
            [](const char& prefix, const std::string& str){
            return str[0] > prefix;
        });
    
    return std::make_pair(lower_it, upper_it);
}

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const std::string& prefix)
{
    auto lower_it = std::lower_bound(
        range_begin, range_end, prefix,
            [](const std::string& str, const std::string& prefix){
            return str.compare(0, prefix.size(), prefix) < 0;
        });
    
    if (lower_it == range_end || (*lower_it).compare(0, prefix.size(), prefix) > 0) {
        return std::make_pair(lower_it, lower_it);
    }
    
    auto upper_it = std::upper_bound(
        range_begin, range_end, prefix,
            [](const std::string& prefix, const std::string& str){
            return str.compare(0, prefix.size(), prefix) > 0;
        });
    
    return std::make_pair(lower_it, upper_it);
}
    

// int main() {
//   const std::vector<std::string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
//   const auto mo_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
//   for (auto it = mo_result.first; it != mo_result.second; ++it) {
//     std::cout << *it << " ";
//   }
//   std::cout << std::endl;
  
//   const auto mt_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
//   std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
//       (mt_result.second - begin(sorted_strings)) << std::endl;
  
//   const auto na_result =
//       FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
//   std::cout << (na_result.first - begin(sorted_strings)) << " " <<
//       (na_result.second - begin(sorted_strings)) << std::endl;
  
//   return 0;
// }