//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once
#include <string>
#include "observer.h"

class Observer;
class Subject {
public:
    virtual ~Subject();

    virtual std::string getValue() = 0;

    virtual void setValue(std::string newValue) = 0;

    virtual bool isRegistered(Observer *o) = 0;

    virtual void registerObserver(Observer *o) = 0;

    virtual void notify() = 0;

    virtual void unregisterObserver(Observer *o) = 0;
};



