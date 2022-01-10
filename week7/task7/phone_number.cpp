#include "phone_number.h"
#include <algorithm>
#include <sstream>

size_t endOfPart(const string& number, size_t start, char sep)
{
    size_t endPart = number.find(sep, start);
    if (endPart == string::npos || endPart == start) { 
        throw invalid_argument("support format +7-495-111-22-33");
    }
    return endPart;
}


PhoneNumber::PhoneNumber(const string& international_number)
{
    if (international_number.empty() || international_number[0] != '+') {
        throw invalid_argument("support format +7-495-111-22-33");
    }
 
    size_t start = 1;
    size_t endPart = endOfPart(international_number, start, '-');
    country_code_ = international_number.substr(start, endPart-start);
    start = endPart + 1;
    endPart = endOfPart(international_number, start, '-');
    city_code_ = international_number.substr(start, endPart-start);
    start = endPart + 1;
    local_number_ = international_number.substr(start);
    if (local_number_.empty()) throw invalid_argument("support format +7-495-111-22-33");
}

string PhoneNumber::GetCountryCode() const{ return country_code_;}

string PhoneNumber::GetCityCode() const{ return city_code_;}

string PhoneNumber::GetLocalNumber() const{ return local_number_;}

string PhoneNumber::GetInternationalNumber() const{
    stringstream ss;
    ss << "+" << country_code_ << "-" << city_code_ << "-" << local_number_;
    return ss.str();
}
