#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <string>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string cmd;
  is >> cmd;

  if (cmd == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;

    int stop_count;
    is >> stop_count;
    vector<string> stops(stop_count);
    for(auto& stop : stops) is >> stop;
    q.stops = stops;
  } else if (cmd == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (cmd == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (cmd == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
  string stop;
  map<string, vector<string>> stops;
  string delimotor = " ";
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.stops.count(r.stop) == 0) {
    os << "No stop";
  } else {
    bool first = true;
    for (const string& bus : r.stops.at(r.stop)) {
      if (!first) {
        os << r.delimotor;
      }
      first = false;
      os << bus;
    }
  }

  return os;
}

struct StopsForBusResponse {
  string bus;
  map<string, vector<string>> buses_to_stop;
  map<string, vector<string>> stops_to_bus;
  string delimotor = " ";
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if(r.buses_to_stop.count(r.bus) == 0) {
    os << "No bus";
  } else {
    for (size_t i = 0; i < r.buses_to_stop.at(r.bus).size(); ++i) {
      string stop = r.buses_to_stop.at(r.bus)[i];
      cout << "Stop " << stop << ": ";
      if (r.stops_to_bus.at(stop).size() == 1) {
        os << "no interchange";
      } else {
        bool first = true;
        for (const string& other_bus : r.stops_to_bus.at(stop)) {
          if (r.bus != other_bus) {
            if (!first) {
              os << r.delimotor;
            }
            first = false;
            os << other_bus;
          }
        }
    }

    if (i + 1 < r.buses_to_stop.at(r.bus).size()) {
        os << endl;
      }
    }
  }
  return os;
}

struct AllBusesResponse {
  map<string, vector<string>> buses_to_stop;
  string delimotor = " ";
};

ostream& operator<<(ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stop.empty()) {
    os << "No buses";
  } else {
    size_t count = r.buses_to_stop.size();
    for (const auto& bus_item : r.buses_to_stop) {
      os << "Bus " << bus_item.first << ": ";
      bool first = true;
      for (const string& stop : bus_item.second) {
        if (!first) os << r.delimotor;
        first = false;
        os << stop;
      }
      --count;
      if (count != 0) {
        os << endl;
      }
    }
  }
 
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for(const auto& stop: stops) stops_to_buses[stop].push_back(bus);
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    return {stop, stops_to_buses};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    return {bus, buses_to_stops, stops_to_buses};
  }

  AllBusesResponse GetAllBuses() const {
    return {buses_to_stops};
  }

private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
