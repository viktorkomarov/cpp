#pragma once
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include "date.h"
#include <string>
#include <functional>
#include <utility>


using queryPredic = std::function<bool(const Date& date, const std::string& event)>;

class Database {
public:
    void Add(const Date& date, const std::string& event);
    size_t RemoveIf(queryPredic predic);
    void Print(std::ostream& os)const;
    std::vector<std::pair<Date, std::string>> FindIf(queryPredic predic);
    std::pair<Date, std::string> Last(const Date& date)const;

private:
    std::map<Date, std::set<std::string>> unique_date_events;
    std::vector<std::pair<Date, std::string>> seq_scan;
    std::map<Date, std::vector<std::string>> storage;
};

std::ostream& operator<<(std::ostream& os, std::pair<Date, std::string>);

void TestDatabaseAdd();