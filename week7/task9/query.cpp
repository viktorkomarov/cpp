#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
  std::string cmd;
  is >> cmd;

  if (cmd == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;

    int stop_count;
    is >> stop_count;
    std::vector<std::string> stops(stop_count);
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