//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once

#include "State.h"

class StateAnomalie : public State {
public:
    StateAnomalie(Moniteur &mon);
    virtual void SensorChange(Capteur *s) override;
};



