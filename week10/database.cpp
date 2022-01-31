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
    auto it = std::remove_if(std::begin(seq_scan), std::end(seq_scan), [predic](const auto& item) {
        return predic(item.first, item.second);
    });
    for(auto from = it; it != seq_scan.end(); ++it) {
        storage[from->first].erase(std::remove(
                storage[from->first].begin(), storage[from->first].end(),
                from->second));
        unique_date_events[from->first].erase(from->second);

        if(storage[from->first].size() == 0) {
            storage.erase(from->first);
        }
    }
    size_t count = seq_scan.end() - it;
    seq_scan.erase(it, std::end(seq_scan));

    return count;
}

std::pair<Date, std::string> Database::Last(const Date& date) const{
    auto it = std::lower_bound(
            std::begin(storage), std::end(storage),
            date, [](const auto& item, const Date& date) {
       return date < item.first;
    });
    if (it == std::end(storage)) throw std::invalid_argument("no dates");

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

    return copies;
}