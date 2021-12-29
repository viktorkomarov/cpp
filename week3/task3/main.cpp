#include <string>
#include <vector>
#include <algorithm>

class SortedStrings {
    public:
      void AddString(const std::string& s) {
          set.push_back(s);
    }
    std::vector<std::string> GetSortedStrings() {
        std::vector<std::string> copy(begin(set), end(set));
        std::sort(begin(copy), end(copy));
        return copy;
    }

    private:
        std::vector<std::string> set;
};