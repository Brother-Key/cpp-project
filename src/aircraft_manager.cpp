#include "aircraft_manager.hpp"

void AircraftManager::add(std::unique_ptr<Aircraft> aircraft)
{
    assert(aircraft != nullptr);
    // TASK_1
    // On déplace la référence du aircraft dans notre liste en utilisant la méthode move
    // sur le Aircraft
    aircrafts.emplace_back(std::move(aircraft));
}


bool AircraftManager::move() {

    // On parcour les références d'aircraft de la liste
    for (auto iter = aircrafts.begin(); iter != aircrafts.end(); )
    {
        // L'iterateur renvoyant des références sur des Aircraft,
        // on déréférence une seconde fois pour obtenir l'Aircraft
        auto& aircraft = **iter;
        if (aircraft.move())
        {
            iter ++;
        }
        else
        {
            iter = aircrafts.erase(iter);
        }
    }

    // On return true car sinon on l'enleve de la move_queue
    // dans l'appel dans timer
    return true;
}