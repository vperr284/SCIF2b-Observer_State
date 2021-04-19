//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once
#include "observer.h"

class ObserverImpl : public Observer {
public:
    ObserverImpl();
    virtual ~ObserverImpl();
    virtual void update(Subject *subject) override;
};



