#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <sstream>
#include <algorithm>

class Date {
public:
    Date(){};
    Date(int y, int m, int d) {
        if (m < 1 || m > 12) throw std::invalid_argument("Month value is invalid: " + std::to_string(m));
        if (d < 1 || d > 31) throw std::invalid_argument("Day value is invalid: " + std::to_string(d));
        year = y;
        month = m;
        day = d;
    }
    int GetDay() const {return day;}
    int GetMonth() const {return month;}
    int GetYear() const {return year;}
private:
    int year = 0;
    int month = 1;
    int day = 1;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) return lhs.GetYear() < rhs.GetYear();
    if (lhs.GetMonth() != rhs.GetMonth()) return lhs.GetMonth() < rhs.GetMonth();
    if (lhs.GetDay() != rhs.GetDay()) return lhs.GetDay() < rhs.GetDay();
    return false;
}

std::istream& operator>>(std::istream& stream, Date& date) {
    std::string date_str;
    stream >> date_str;
    std::stringstream str(date_str);
    int y = 0, m = 0, d = 0;
    char op1, op2;

    str >> y >> op1 >> m >> op2 >> d;
    if(!str) throw std::invalid_argument("Wrong date format: " + str.str());
    if (str.peek() != EOF) throw std::invalid_argument("Wrong date format: " + str.str());
    if (op1 != '-' || op2 != '-') throw std::invalid_argument("Wrong date format: " + str.str());

    date = Date(y,m,d);
    return stream;
}

std::string buildTimeFormat(int d, int len) {
    if(len == 2){
        if (d > 9) return std::to_string(d);
        return "0" + std::to_string(d);
    } else if (len == 4) {
        if (d < 10) return "000" + std::to_string(d);
        if (d < 100) return "00" + std::to_string(d);
        if (d < 1000) return "0" + std::to_string(d);
        return  std::to_string(d);
    }

    return std::to_string(d);
}

std::ostream& operator<<(std::ostream& stream, const Date& date) {
    stream << buildTimeFormat(date.GetYear(), 4) << "-" << buildTimeFormat(date.GetMonth(), 2) << "-" << buildTimeFormat(date.GetDay(),2);
    return stream;
}

class EventDB {
public:
    void AddEvent(const Date& date, const std::string event) {events_by_date[date].insert(event);}
    std::string DelEvent(const Date& date, const std::string event) {
        if (events_by_date[date].count(event) == 0) {
            return "Event not found";
        }
        events_by_date[date].erase(event);
        return "Deleted successfully";
    }
    std::string DelAllEvents(const Date& date) {
        int count = events_by_date[date].size();
        events_by_date.erase(date);
        std::stringstream str;
        str<<"Deleted " << count <<" events";
        return str.str();
    }
    std::set<std::string> FindEvents(const Date& date) const {
        if (events_by_date.count(date)) {
            return events_by_date.at(date);
        }
        return  std::set<std::string>();
    }
    std::map<Date, std::set<std::string> > AllEvents() const {
        return events_by_date;
    }
private:
    std::map<Date, std::set<std::string> > events_by_date;
};

int main() {
  EventDB db;
    
  std::string command;
  while (std::getline(std::cin, command)) {
    std::stringstream cmd(command);
    cmd >> command;
    try{
      if (command == "Add") {
        Date date;
        std::string event;
        cmd >> date >> event;
        db.AddEvent(date, event);
      } else if(command == "Del") {
        Date date;
        cmd >> date;
        if(cmd.peek() == ' ') {
            std::string event;
            cmd >> event;
            std::cout << db.DelEvent(date, event) << std::endl;
        } else {
            std::cout << db.DelAllEvents(date) << std::endl;
        }
      } else if(command == "Find") {
        Date date;
        cmd >> date;
        
        std::set<std::string> events = db.FindEvents(date);
        for (const std::string& ev : events) {
            std::cout << ev << std::endl;
        }
      } else if(command == "Print") {
          std::map<Date, std::set<std::string> > events = db.AllEvents();
          for(const auto& item : events) {
            for(const auto& event : item.second) {
                std::cout << item.first << " " << event << std::endl;
            }
          }
      } else if (command == "") {
          continue;
      } else {
          std::cout << "Unknown command: " << command << std::endl;
      }
    } catch(std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
        break;
    }
  }

  return 0;
}