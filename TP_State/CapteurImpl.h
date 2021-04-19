//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once

#include <list>
#include "Capteur.h"

class CapteurImpl : public Capteur {
public:
    CapteurImpl(std::list<double> &s);
    virtual ~CapteurImpl();
    virtual void applyChanges();

private:
    std::list<double> source;
    std::list<double>::const_iterator courant;
};



