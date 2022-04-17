#pragma once

#include <vector>
#include "aircraft.hpp"

// TASK_1
// Mise en place de la classe AircraftManager permettant la gestion des Aircraft
// Dans la simulation

// Dans un premier temps le but etant que notre classe contient a present tout les
// Aircraft present dans la simulation, pour cela on met en place une liste d'Aricraft

// 1 - Nous avons donc très vite besoin d'une méthode add afin d'ajouter des Aircraft


class AircraftManager
{
private:

    // C'est une liste de unique_ptr car il ne faut surtout pas faire de copie d'un Aircraft
    std::vector<std::unique_ptr<Aircraft>> aircrafts;

public:
    

    void add(std::unique_ptr<Aircraft> aircraft);

};

