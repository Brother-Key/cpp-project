#pragma once

#include <string>
#include "aircraft_types.hpp"
#include "aircraft.hpp"
#include "airport.hpp"

// TASK _1
// Creation de notre factory

class AircraftFactory
{
private:

    std::set<std::string> flying_nb = {};

    // TASK_1 Init all aircraft types
    const std::array<AircraftType, 3> aircraft_types {
        AircraftType { .02f, .05f, .02f, MediaPath { "l1011_48px.png" } },
        AircraftType { .02f, .05f, .02f, MediaPath { "b707_jat.png" } },
        AircraftType { .04f, .10f, .04f, MediaPath { "concorde_af.png" } }
    };
    
public:

    const std::array<std::string, 8> airlines = {"AF", "LH", "EY", "DL", "KL", "BA", "AY", "EY"};

    std::unique_ptr<Aircraft> create_aircraft(const AircraftType& type, Airport& airport)
    {
        const std::string flight_number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
        const float angle       = (rand() % 1000) * 2 * 3.141592f / 1000.f; // random angle between 0 and 2pi
        const Point3D start     = Point3D { std::sin(angle), std::cos(angle), 0 } * 3 + Point3D { 0, 0, 2 };
        const Point3D direction = (-start).normalize();

        return std::make_unique<Aircraft>(type, flight_number, start, direction, airport.get_tower());
    }

    std::unique_ptr<Aircraft> create_random_aircraft(Airport& airport)
    {
        return create_aircraft(aircraft_types[rand() % 3], airport);
    }
    
};

