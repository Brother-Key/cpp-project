#pragma once

#include <vector>
#include "aircraft.hpp"

// TASK_1
// Mise en place de la classe AircraftManager permettant la gestion des Aircraft
// Dans la simulation

// Dans un premier temps le but etant que notre classe contient a present tout les
// Aircraft present dans la simulation, pour cela on met en place une liste d'Aricraft

// 1 - Nous avons donc très vite besoin d'une méthode add afin d'ajouter des Aircraft
// 2 - Notre AircraftManager herite de DynamicObject car il est demander dans le sujet que
// le AircraftManager soit ajouter dans la move_queue qui prend en parametre des DynamicObject
// 3 - Implémentation de la méthode move

class AircraftManager : public GL::DynamicObject
{
private:

    // C'est une liste de unique_ptr car il ne faut surtout pas faire de copie d'un Aircraft
    std::vector<std::unique_ptr<Aircraft>> aircrafts;

public:
    
    void add(std::unique_ptr<Aircraft> aircraft);

    // TASK_1
    // Cet méthode nous permet d'appeler move sur les aircrafts stocke dans notre liste
    // lors de l'appel a move dans le timer
    bool move() override;

};

