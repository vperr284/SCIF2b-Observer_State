//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once
#include "subject.h"
#include <list>

class SubjectImpl : public Subject {
private:
    std::list<Observer *> observers;
    std::string value;
public:
    SubjectImpl();
    virtual ~SubjectImpl();

    virtual void notify();

    virtual bool isRegistered(Observer *o);

    virtual void registerObserver(Observer *o);

    virtual void unregisterObserver(Observer *o);

    virtual void setValue(std::string newValue);

    virtual std::string getValue();
};

