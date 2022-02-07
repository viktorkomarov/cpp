#include "airline_ticket.h"
#include "test_runner.h"

#include <sstream>
using namespace std;

#define UPDATE_FIELD(ticket, field, values) \
    {map<string, string>::const_iterator it = values.find(#field); \
    if (it != values.end() ) { \
        istringstream is(it->second); \
        is >> ticket.field;\
    }}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

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


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
