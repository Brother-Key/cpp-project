#include "aircraft_manager.hpp"

void AircraftManager::add(std::unique_ptr<Aircraft> aircraft)
{
    this->aircrafts.emplace_back(std::move(aircraft));
}
