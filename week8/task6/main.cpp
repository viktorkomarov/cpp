#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  std::nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(std::vector<Person> persons)
{
    auto partFemaleIt = std::partition(begin(persons), end(persons), [](const Person& person)->bool{
        return person.gender == Gender::MALE;
    });

    auto noneEmployedFemale = std::partition(partFemaleIt, end(persons),[](const Person& person)->bool{
        return !person.is_employed;
    });

    auto noneEmployedMale = std::partition(begin(persons), partFemaleIt,[](const Person& person)->bool{
        return !person.is_employed;
    });

    std::cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << std::endl;
    std::cout << "Median age for females = " << ComputeMedianAge(partFemaleIt, end(persons)) << std::endl;
    std::cout << "Median age for males = " << ComputeMedianAge(begin(persons), partFemaleIt) << std::endl;
    std::cout << "Median age for employed females = " << ComputeMedianAge(noneEmployedFemale, end(persons)) << std::endl;
    std::cout << "Median age for unemployed females = "<< ComputeMedianAge(partFemaleIt, noneEmployedFemale) << std::endl;
    std::cout << "Median age for employed males = " << ComputeMedianAge(noneEmployedMale, partFemaleIt) << std::endl;
    std::cout << "Median age for unemployed males = " << ComputeMedianAge(begin(persons), noneEmployedMale) << std::endl;
}


int main() {
  std::vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}