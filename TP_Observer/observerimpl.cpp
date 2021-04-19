//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include <iostream>
#include "observerimpl.h"

ObserverImpl::ObserverImpl() {}
ObserverImpl::~ObserverImpl() {}

void ObserverImpl::update(Subject *subject) {
    std::cout << "L'observateur observe... " << this << " : le sujet de l'experience " << subject << " se situe dans l'etat "
              << subject->getValue() << std::endl;
}
