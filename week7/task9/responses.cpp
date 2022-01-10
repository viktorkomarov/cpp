#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
  if (r.stops.count(r.stop) == 0) {
    os << "No stop";
  } else {
    bool first = true;
    for (const std::string& bus : r.stops.at(r.stop)) {
      if (!first) {
        os << r.delimotor;
      }
      first = false;
      os << bus;
    }
  }

  return os;
}


std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
  if(r.buses_to_stop.count(r.bus) == 0) {
    os << "No bus";
  } else {
    for (size_t i = 0; i < r.buses_to_stop.at(r.bus).size(); ++i) {
      std::string stop = r.buses_to_stop.at(r.bus)[i];
      os << "Stop " << stop << ": ";
      if (r.stops_to_bus.at(stop).size() == 1) {
        os << "no interchange";
      } else {
        bool first = true;
        for (const std::string& other_bus : r.stops_to_bus.at(stop)) {
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
        os << std::endl;
      }
    }
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stop.empty()) {
    os << "No buses";
  } else {
    size_t count = r.buses_to_stop.size();
    for (const auto& bus_item : r.buses_to_stop) {
      os << "Bus " << bus_item.first << ": ";
      bool first = true;
      for (const std::string& stop : bus_item.second) {
        if (!first) os << r.delimotor;
        first = false;
        os << stop;
      }
      --count;
      if (count != 0) {
        os << std::endl;
      }
    }
  }
 
  return os;
}
