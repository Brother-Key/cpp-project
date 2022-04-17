#pragma once

#include "aircraft_manager.hpp"
#include "aircraft_factory.hpp"

class Airport;
struct AircraftType;

class TowerSimulation
{
private:
    bool help        = false;
    Airport* airport = nullptr;
    AircraftManager aircraft_manager; // TASK_1
    AircraftFactory* aircraft_factory = nullptr; // TASK_1

    TowerSimulation(const TowerSimulation&) = delete;
    TowerSimulation& operator=(const TowerSimulation&) = delete;

    // TASK_1 nos méthode renvoie maintenant des unique_ptr afin de renvoyer
    // l'Aircraft crée que l'on utilise ensuite pour ajouter dans notre AircraftManager
    // std::unique_ptr<Aircraft> create_aircraft(const AircraftType& type) const;
    // void create_random_aircraft();
    
    void create_keystrokes();
    void display_help() const;

    void init_airport();

public:
    TowerSimulation(int argc, char** argv);
    ~TowerSimulation();

    void launch();
};
