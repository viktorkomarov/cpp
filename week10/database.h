#pragma once
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include "date.h"
#include <utility>

class Database {
public:
    void Add(const Date& date, const std::string& event);
    template<typename Op> size_t RemoveIf(Op predic);
    void Print(std::ostream& os)const;
    template<typename Op>
    std::vector<std::pair<Date, std::string>> FindIf(Op predic);
    std::pair<Date, std::string> Last(const Date& date)const;

private:
    std::map<Date, std::set<std::string>> unique_date_events;
    std::vector<std::pair<Date, std::string>> seq_scan;
    std::map<Date, std::vector<std::string>> storage;
};

std::ostream& operator<<(std::ostream& os, std::pair<Date, std::string>);