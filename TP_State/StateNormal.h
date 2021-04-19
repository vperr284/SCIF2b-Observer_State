//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once

#include "Moniteur.h"

class Moniteur;

class State;

class Capteur;

class StateNormal : public State {
public :
    StateNormal(Moniteur &mon);
    virtual ~StateNormal();
    virtual void SensorChange(Capteur *s) override;

private:
    double min_sensor = 0;
    double max_sensor = 0;
};


