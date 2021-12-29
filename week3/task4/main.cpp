#include <map>
#include <string>
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
};

// int main() {
//     Person person;

//     person.ChangeFirstName(1965, "Polina");
//     person.ChangeLastName(1967, "Sergeeva");
//     for (int year : {1900, 1965, 1990}) {
//         std::cout << person.GetFullName(year) << std::endl;
//     }
  
//     person.ChangeFirstName(1970, "Appolinaria");
//     for (int year : {1969, 1970}) {
//         std::cout << person.GetFullName(year) << std::endl;
//     }
  
//     person.ChangeLastName(1968, "Volkova");
//     for (int year : {1969, 1970}) {
//         std::cout << person.GetFullName(year) << std::endl;
//     }
    
//     return 0;
// }