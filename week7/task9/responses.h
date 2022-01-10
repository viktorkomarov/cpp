#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>

struct BusesForStopResponse {
  std::string stop;
  std::map<std::string, std::vector<std::string> > stops;
  std::string delimotor = " ";
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  std::string bus;
  std::map<std::string, std::vector<std::string> > buses_to_stop;
  std::map<std::string, std::vector<std::string> > stops_to_bus;
  std::string delimotor = " ";
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string> > buses_to_stop;
  std::string delimotor = " ";
};

std::ostream& operator<<(std::ostream& os, const AllBusesResponse& r);