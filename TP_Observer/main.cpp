//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include <iostream>
#include "subjectimpl.h"
#include "observerimpl.h"

int main() {
    std::cout << "TP1 : Patron de conception Observer" << std::endl;

    std::cout << " " << std::endl;

    Observer *obs1(new ObserverImpl());
    Observer *obs2(new ObserverImpl());
    Subject *sub1(new SubjectImpl());
    Subject *sub2(new SubjectImpl());

    sub1->registerObserver(obs1);
    sub1->setValue("Cobaye 1");
    sub2->registerObserver(obs2);
    sub1->setValue("Je me sens bienvenu dans cette experience");

    std::cout << " " << std::endl;

    sub2->setValue("Ca a l'air sympa ici");
    sub1->setValue("Ouais c'est pas mal");

    std::cout << " " << std::endl;

    std::cout << sub1->isRegistered(obs1) << std::endl;

    std::cout << " " << std::endl;

    sub1->unregisterObserver(obs1);

    std::cout << sub1->isRegistered(obs1) << std::endl;

    return 0;
}
