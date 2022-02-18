#include <map>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

int64_t last_day(int64_t clock_){
    return  clock_ - 86400;
}

class Hotel{
public:
    void Book(int64_t tick, int64_t client_id, int rooms) {
        history[tick].push_back({client_id, rooms});
        reserved_rooms += rooms;
        ++clients_[client_id];
    }
    uint64_t Clients(uint64_t tick){
        clear(last_day(tick));
        return clients_.size();
    }
    uint64_t Rooms(uint64_t tick){
        clear(last_day(tick));
        return reserved_rooms;
    }
private:
    void clear(int64_t tick){
        auto it = history.upper_bound(tick);
        for(auto from = history.begin(); from != it; from = std::next(from))
        {
            for (const auto& item : from->second) {
                reserved_rooms -= item.second;
                --clients_[item.first];
                if (clients_[item.first] == 0) clients_.erase(item.first);
            }
        }
        history.erase(history.begin(), it);
    }
    uint64_t reserved_rooms = 0;
    std::map<int64_t, int> clients_;
    std::map<int64_t, std::vector<std::pair<int64_t, int>>> history;
};

class EventRouter{
public:
    void Book(const std::string& hotel,int64_t tick, int64_t client_id, int room_count)
    {
        clock_ = tick;
        hotels_[hotel].Book(tick, client_id, room_count);
    }

    uint64_t  Clients(const std::string& hotel) {
        if (hotels_.count(hotel) == 0) return 0;
        return hotels_.at(hotel).Clients(clock_);
    }

    uint64_t  Rooms(const std::string& hotel)  {
        if (hotels_.count(hotel) == 0) return 0;
        return hotels_.at(hotel).Rooms(clock_);
    }
private:
    int64_t clock_ = 0;
    std::map<std::string, Hotel> hotels_;
};

int main()
{
    int query_count;
    std::cin >> query_count;

    EventRouter router;
    for (int query_id = 0; query_id < query_count; ++query_id) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "BOOK"){
            int64_t time = 0;
            std::string hotel;
            int64_t client_id = 0;
            int rooms = 0;
            std::cin >> time >> hotel >> client_id >> rooms;
            router.Book(hotel, time, client_id, rooms);
        } else if(cmd == "CLIENTS") {
            std::string hotel;
            std::cin >> hotel;
            std::cout << router.Clients(hotel) << "\n";
        } else if(cmd == "ROOMS") {
            std::string hotel;
            std::cin >> hotel;
            std::cout << router.Rooms(hotel) << "\n";
        }
    }
}