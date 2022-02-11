#include "test_runner.h"
#include <utility>
#include <vector>

template<typename T>
class Table{
public:
    Table(size_t row, size_t column) : row_(row), column_(column), table(row)
    {
      for (auto& i : table) i = std::vector<T>(column_);
    };
    void Resize(size_t row, size_t column) {
      table.resize(row);
      for(auto& t : table) t.resize(column);
      row_ = row;
      column_ =column;
    }
    std::vector<T>& operator[](size_t row)
    {
        return table[row];
    }
    const std::vector<T>& operator[](size_t row) const
    {
        return table[row];
    }
    std::pair<size_t, size_t> Size()const {
      if (row_ == 0 || column_ == 0) return {0,0};
      return {row_, column_};
    }
private:
  size_t row_;
  size_t column_;
  std::vector<std::vector<T>> table;
};

// void TestTable() {
//   Table<int> t(1, 1);
//   ASSERT_EQUAL(t.Size().first, 1u);
//   ASSERT_EQUAL(t.Size().second, 1u);
//   t[0][0] = 42;
//   ASSERT_EQUAL(t[0][0], 42);
//   t.Resize(3, 4);
//   ASSERT_EQUAL(t.Size().first, 3u);
//   ASSERT_EQUAL(t.Size().second, 4u);
// }

// int main() {
//   TestRunner tr;
//   RUN_TEST(tr, TestTable);
//   return 0;
// }
