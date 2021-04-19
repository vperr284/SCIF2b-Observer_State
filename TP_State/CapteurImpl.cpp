//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include "CapteurImpl.h"

CapteurImpl::CapteurImpl(std::list<double> &s) : source(s), courant(source.cbegin()) {
}

void CapteurImpl::applyChanges() {
    if (courant != source.cend()) {
        std::cout << "Changement de valeur : " << *courant << std::endl;
        setValue(*courant);
        courant++;
    }
}

CapteurImpl::~CapteurImpl() {}
