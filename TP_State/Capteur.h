//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once

#include "Moniteur.h"
#include <list>

class Moniteur;

class Capteur {
public:
    Capteur();
    virtual ~Capteur();
    void addObserver(Moniteur *m);
    void removeObserver(Moniteur *m);
    bool isObserving(Moniteur *m);
    virtual double getValue();
    virtual void setValue(double newValue);
    std::string getName();
    void setName(std::string newName);

private:
    std::string Name;
    double Value;
    std::list<Moniteur *> List_Observers;

protected:
    void notifyObservers();
};



