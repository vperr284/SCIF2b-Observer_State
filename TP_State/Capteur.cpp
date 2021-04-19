//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include "Capteur.h"
#include <algorithm>
#include <iostream>

using namespace std;

Capteur::Capteur() : Value(0.0), Name("unname") {
}

Capteur::~Capteur() {
}

void Capteur::addObserver(Moniteur *m) {
    if (not isObserving(m)) {
        List_Observers.push_front(m);
        cerr << "Ajout du " << m->getName() << " dans le " << Name << endl;
        return;
    }
    cerr << "Le " << m->getName() << " ne peut pas etre ajoute dans le " << Name
         << " (occupe)" << endl;
}

void Capteur::removeObserver(Moniteur *m) {
    if (isObserving(m)) {
        List_Observers.remove(m);
        cerr << "Suppression du " << m->getName() << " dans le " << Name << endl;
        return;
    }
    cerr << "Le " << m->getName() << " ne peut pas etre supprime du " << Name
         << " (occupe)" << endl;
}

bool Capteur::isObserving(Moniteur *m) {
    return (std::find(List_Observers.cbegin(), List_Observers.cend(), m) != List_Observers.cend());
}

double Capteur::getValue() {
    return Value;
}

void Capteur::setValue(double newValue) {
    Value = newValue;
    notifyObservers();
}

void Capteur::notifyObservers() {
    for (std::list<Moniteur *>::const_iterator iter = List_Observers.cbegin(); iter != List_Observers.cend(); iter++) {
        (*iter)->update(this);
    }
}

std::string Capteur::getName() {
    if (Name != "unname") {
        return Name;
    }
    return to_string(reinterpret_cast<std::uintptr_t>(this));
}

void Capteur::setName(std::string newName) {
    Name = newName;
}
