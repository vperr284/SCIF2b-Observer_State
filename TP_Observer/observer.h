//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once
#include "subject.h"

class Subject;
class Observer {
public:
    virtual ~Observer();

    virtual void update(Subject *s) = 0;
};



