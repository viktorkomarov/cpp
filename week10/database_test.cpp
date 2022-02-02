#include "database.h"
#include "test_runner.h"
#include "date.h"
#include <string>
#include <vector>
#include <utility>

void TestDatabaseAdd()
{
    {
        Database db;
        db.Add({2017,1,1}, "simple event");
        auto predic = [](const Date& date, const std::string& event){
            return date == Date{2017,1,1};
        };
        auto res = db.FindIf(predic);
        std::vector<std::pair<Date, std::string>>expected = {{{2017,1,1}, "simple event"}};
        AssertEqual(res, res, "simple add");
    }
    {
        Database db;
        db.Add({2017,1,1}, "simple event");
        auto predic = [](const Date& date, const std::string& event){
            return date == Date{2017,1,1};
        };
        auto res = db.FindIf(predic);
        std::vector<std::pair<Date, std::string>>expected = {{{2017,1,1}, "simple event"}};
        AssertEqual(res, res, "double add");
    }
    {
        Database db;
        db.Add({2017,1,1}, "simple event");
        auto predic = [](const Date& date, const std::string& event){
            return date == Date{2018,1,1};
        };
        auto res = db.FindIf(predic);
        std::vector<std::pair<Date, std::string>>expected;
        AssertEqual(res, res, "empty date");
    }
    {
        Database db;
        db.Add({2017,1,1}, "simple event");
        auto predic = [](const Date& date, const std::string& event){
            return event == "simple event";
        };
        auto res = db.FindIf(predic);
        std::vector<std::pair<Date, std::string>>expected = {{{2017,1,1}, "simple event"}};
        AssertEqual(res, res, "fitler by event");
    }
}