//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma  once

#include "State.h"
#include "Moniteur.h"

class Moniteur;

class State;

class StatePanne : public State {
public:
    StatePanne(Moniteur &mon);
    virtual void SensorChange(Capteur *s) override;
};










