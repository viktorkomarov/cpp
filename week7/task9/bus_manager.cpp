#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
    buses_to_stops[bus] = stops;
    for(const auto& stop: stops) stops_to_buses[stop].push_back(bus);
}

BusesForStopResponse  BusManager::GetBusesForStop(const std::string& stop) const {
    return {stop, stops_to_buses};
}

StopsForBusResponse  BusManager::GetStopsForBus(const std::string& bus) const {
    return {bus, buses_to_stops, stops_to_buses};
}

AllBusesResponse  BusManager::GetAllBuses() const {
    return {buses_to_stops};
}
