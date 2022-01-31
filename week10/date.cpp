#include "date.h"
#include <string>
#include <stdexcept>
#include <tuple>
#include <iomanip>

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw std::logic_error("Month value is invalid: " + std::to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw std::logic_error("Day value is invalid: " + std::to_string(new_day));
    }
    day = new_day;
}

int Date::GetDay() const {return day;}
int Date::GetMonth() const {return month;}
int Date::GetYear() const {return year;}

bool operator<(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        < std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator==(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
           == std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


std::ostream& operator<<(std::ostream& stream, const Date& date) {
    stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}

bool ok = true;

Date ParseDate(std::istringstream& date_stream) {
    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);

    if (!ok) {
        throw std::logic_error("Wrong date format");
    }

    return Date(year, month, day);
}