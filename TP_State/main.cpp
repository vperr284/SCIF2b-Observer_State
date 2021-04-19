//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include <iostream>
#include "Moniteur.h"
#include "CapteurImpl.h"
#include <Windows.h>

void test1() {
    std::cerr << "-----------------------------------------" << std::endl;
    std::cerr << "Premier test: cas cerr avec deux capteurs" << std::endl;

    Sleep(500);

    //Initialisation

    Moniteur M1;

    std::list<double> L1{3, 4.5, 65, 150};
    std::list<double> L2{6, 3.2, 5.345, 1351};

    M1.setName("Moniteur 1");

    CapteurImpl C1(L1);
    CapteurImpl C2(L2);
    C1.setName("Capteur 1");
    C2.setName("Capteur 2");

    std::list<Capteur *> L{&C1};
    M1.setupSensors(L);
    M1.setHighLimit(140);
    M1.setNmax(5);

    //Demande de l'automate

    C1.applyChanges();
    Sleep(100);
    C1.applyChanges();
    Sleep(100);
    C2.applyChanges();
    Sleep(100);
    C2.applyChanges();
    Sleep(100);

    C1.applyChanges();
    Sleep(100);
    C1.applyChanges();
    Sleep(100);
    C2.applyChanges();
    Sleep(100);
    C2.applyChanges();
    Sleep(100);

    C2.applyChanges();
    Sleep(100);
    C2.applyChanges();
    Sleep(100);
    C1.applyChanges();
    Sleep(100);
    C1.applyChanges();
    Sleep(100);

    M1.reset();
}

void test2() {
    std::cerr << "------------------------------" << std::endl;
    std::cerr << "Deuxieme test: un seul capteur" << std::endl;

    Sleep(500);

    Moniteur M1;

    std::list<double> L1{1, 2, 3.4, 5, 6, 8, 14};
    std::list<double> L2{9, 5, 234, 6, 1, 0, 9};

    M1.setName("Moniteur 1");

    CapteurImpl C1(L1);
    C1.setName("Capteur 1");
    std::list<Capteur *> L{&C1};
    M1.setupSensors(L);
    M1.setHighLimit(10);
    M1.setNmax(4);

    C1.applyChanges();
    Sleep(100);
    C1.applyChanges();
    Sleep(100);
    C1.applyChanges();
    Sleep(100);
    C1.applyChanges();
    Sleep(100);

    M1.reset();
}

int main() {
    std::cerr << "Debut du main.cpp" << std::endl;

    Sleep(500);

    test1();

    Sleep(500);

    test2();

    return 0;
}
