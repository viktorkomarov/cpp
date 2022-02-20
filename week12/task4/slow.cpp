#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <numeric>

using namespace std;

class ReadingManager {
public:
  ReadingManager():page_to_count_users(1000, 0){}

  void Read(int user_id, int page_count) {
    if (user_to_page.count(user_id) != 0) {
        page_to_count_users[user_to_page[user_id]]--;
    }
    user_to_page[user_id] = page_count;
    page_to_count_users[page_count]++;
  }

  double Cheer(int user_id) const {
    if (user_to_page.count(user_id) == 0) {
        return 0;
    }

    if (user_to_page.size() == 1) {
        return 1;
    }
    int total_users_before = accumulate(begin(page_to_count_users),
                                        next(page_to_count_users.begin(), user_to_page.at(user_id)),
                                        0);


    // По умолчанию деление целочисленное, поэтому
    // нужно привести числитель к типу double.
    // Простой способ сделать это — умножить его на 1.0.
    return (total_users_before * 1.0) / (user_to_page.size() - 1);
  }

private:
  map<int, int> user_to_page;
  vector<int> page_to_count_users;
};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}