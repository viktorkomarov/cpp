#include "airline_ticket.h"
#include "test_runner.h"

#include <sstream>
using namespace std;

ostream& operator<<(ostream& os, const AirlineTicket& item)
{
  os << item.airline << std::endl;
  return os;
}

ostream& operator<<(ostream& os, const Date& item)
{
  os << item.year << "-" << item.month << "-" << item.day << std::endl;
  return os;
}

ostream& operator<<(ostream& os, const Time& item)
{
  os << item.hours << ":" << item.minutes << std::endl;
  return os;
}

istream& operator>>(istream& os, Date& item)
{
  int year = 0;
  int month = 0;
  int day = 0;
  char del1 = ' ';
  char del2 = ' ';

  os >> year >> del1 >> month >> del2 >> day;
  item = Date{year, month, day};
  return os;
}

istream& operator>>(istream& os, Time& item)
{
  int hours = 0;
  int minutes = 0;
  char del = ' ';

  os >> hours >> del >> minutes;
  item = Time{hours, minutes};
  return os;
}

bool operator<(const Date& lhs, const Date& rhs)
{
  return  std::make_tuple(lhs.year, lhs.month, lhs.day) < std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator<(const Time& lhs, const Time& rhs)
{
  return std::make_tuple(lhs.hours, lhs.minutes) < std::make_tuple(rhs.hours, rhs.minutes);
}

bool operator==(const Date& lhs, const Date& rhs)
{
  return  std::make_tuple(lhs.year, lhs.month, lhs.day) == std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Time& lhs, const Time& rhs)
{
  return std::make_tuple(lhs.hours, lhs.minutes) == std::make_tuple(rhs.hours, rhs.minutes);
}

#define UPDATE_FIELD(ticket, field, values) \
    {map<string, string>::const_iterator it = values.find(#field); \
    if (it != values.end() ) { \
        istringstream is(it->second); \
        is >> ticket.field;\
    }}

// int main() {
//   TestRunner tr;
//   RUN_TEST(tr, TestUpdate);
// }
