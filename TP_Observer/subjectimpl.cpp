//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include "subjectimpl.h"
#include <iostream>
#include <algorithm>

SubjectImpl::SubjectImpl() {}
SubjectImpl::~SubjectImpl() {}

void SubjectImpl::setValue(std::string newValue) {
    value = newValue;
    notify();
}

std::string SubjectImpl::getValue() {
    return value;
}

void SubjectImpl::notify() {
    for (std::list<Observer *>::const_iterator iter = observers.cbegin(); iter != observers.cend(); iter++) {
        (*iter)->update(this);
    }
}

bool SubjectImpl::isRegistered(Observer *o) {
    std::list<Observer *>::const_iterator position = std::find(observers.cbegin(), observers.cend(), o);
    return position != observers.cend();
    notify();
}

void SubjectImpl::registerObserver(Observer *o) {
    observers.push_back(o);
    notify();
}

void SubjectImpl::unregisterObserver(Observer *o) {
    observers.remove(o);
    notify();
}
