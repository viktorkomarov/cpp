#include "database.h"
#include <iostream>
#include <set>
#include <algorithm>
void Database::Add(const Date& date, const std::string& event) {
    if (unique_date_events.count(date) == 0  || unique_date_events.at(date).count(event) == 0) {
        unique_date_events[date].insert(event);
        seq_scan.push_back({date, event});
        storage[date].push_back(event);
    }
}
void Database::Print(std::ostream& os) const {
    for (const auto& item : storage) {
        for (const std::string& event : item.second) {
          os << item.first << " " << event << std::endl;
        }
    }
}

size_t Database::RemoveIf(queryPredic predic) {
    std::vector<std::pair<Date, std::string>> copies;
    auto it = std::remove_copy_if(std::begin(seq_scan), std::end(seq_scan),
                                  std::back_inserter(copies),
          [predic](const auto& item) {return !predic(item.first, item.second);});
    for(auto from = std::begin(copies); from != std::end(copies); ++from) {
        storage[from->first].erase(std::remove(
                storage[from->first].begin(), storage[from->first].end(),
                from->second));
        unique_date_events[from->first].erase(from->second);

        if(storage[from->first].size() == 0) {
            storage.erase(from->first);
        }
    }
    seq_scan.erase(std::next(std::begin(seq_scan), copies.size()), std::end(seq_scan));

    return copies.size();
}

std::pair<Date, std::string> Database::Last(const Date& date) const{
    auto it = storage.lower_bound(date);
    if (it == storage.begin() && !(it->first == date)) throw std::invalid_argument("no dates");
    if (it == storage.end()) it = std::prev(it);

    return std::make_pair(it->first,*std::prev(std::end(it->second)));
}

std::ostream& operator<<(std::ostream& os, std::pair<Date, std::string> pair)
{
    os << pair.first << " " << pair.second;
    return os;
}

std::vector<std::pair<Date, std::string>> Database::FindIf(queryPredic predic)
{
    std::vector<std::pair<Date, std::string>> copies;
    auto it = std::copy_if(std::begin(seq_scan), std::end(seq_scan), std::back_inserter(copies),[predic](const auto& item) {
        return predic(item.first, item.second);
    });
    std::sort(std::begin(copies), std::end(copies));

    return copies;
}