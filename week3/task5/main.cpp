#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Person {
public:
  void ChangeFirstName(int year, const std::string& first_name) {
    name_by_year[year] = first_name;
  }
  void ChangeLastName(int year, const std::string& last_name) {
    surname_by_year[year] = last_name;
  }
  std::string GetFullName(int year) {
      auto name = get_value(year, name_by_year);
      auto surname = get_value(year, surname_by_year);

      if (name == "" && surname == "") return "Incognito";
      if (name != "" && surname == "") return name + " with unknown last name";
      if (name == "" && surname != "") return surname + " with unknown first name";
      return name + " " + surname;
  }

  std::string GetFullNameWithHistory(int year) {
      auto name = get_value(year, name_by_year);
      auto surname = get_value(year, surname_by_year);
      auto name_history = build_history(get_values_before(year, name_by_year));
      auto surname_history = build_history(get_values_before(year, surname_by_year));

      if (name == "" && surname == "") return "Incognito";
      if (name != "" && surname == "") return name + name_history + " with unknown last name";
      if (name == "" && surname != "") return surname + surname_history + " with unknown first name" ;
      return name + name_history + " " + surname + surname_history;
  }
private:
  std::map<int, std::string> name_by_year;
  std::map<int, std::string> surname_by_year;

  std::string get_value(int year, const std::map<int, std::string>& values) {
      std::string res;
      for(auto& item : values) {
          if (item.first <= year) res = item.second;
      }
      return res;
  }

  std::string build_history(const std::vector<std::string>& val) {
      if (val.empty()) return "";

      std::string res = " (";
      for(size_t i = 0; i < val.size(); ++i) {
          res += val[i];
          if (i != val.size()-1) res += ", ";
      }
      return res + ")";
  }

  std::vector<std::string> get_values_before(int year, const std::map<int, std::string>& values) {
      std::vector<std::string> res;
      for(auto& item : values) {
          if (item.first <= year) {
              if (res.empty() || (res[res.size()-1] != item.second)) {
                  res.push_back(item.second);
              }
          }
      }
      if (!res.empty()) res.pop_back();
      std::reverse(begin(res), end(res));
      return res;
  }
};

// int main() {
//   Person person;

//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Appolinaria");

//   person.ChangeLastName(1965, "Sergeeva");
//   person.ChangeLastName(1965, "Volkova");
//   person.ChangeLastName(1965, "Volkova-Sergeeva");

//   for (int year : {1964, 1965, 1966}) {
//     std::cout << person.GetFullNameWithHistory(year) << std::endl;
//   }

//   return 0;
// }