//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once

#include "Capteur.h"
#include "Moniteur.h"

class Moniteur;

class Capteur;

class State {
public:
    State(Moniteur &mon);
    virtual ~State();
    virtual void SensorChange(Capteur *s) = 0;

protected:
    Moniteur &monitor;
};



