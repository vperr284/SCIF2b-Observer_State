//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include <map>
#include <cfloat>
#include "Moniteur.h"
#include "StateNormal.h"
#include "StateAnomalie.h"
#include "StatePanne.h"


Moniteur::Moniteur() : HighLimit(DBL_MAX), currentState(NORMAL), Name("unname"), Nmax(INT32_MAX) {
    alarmStream = &std::cerr;
    automaton[NORMAL] = new StateNormal(*this);
    automaton[ANOMALY] = new StateAnomalie(*this);
    automaton[FAILURE] = new StatePanne(*this);

    currentState = NORMAL;
}

void Moniteur::setupSensors(std::list<Capteur *> &SensorsToMonitor) {
    void sensorChange(Capteur *s);
    for (auto iterSensor(SensorsToMonitor.cbegin()); iterSensor != SensorsToMonitor.cend(); iterSensor++) {
        (*iterSensor)->addObserver(this);
    };
    Sensors = SensorsToMonitor;
    activeSensors = SensorsToMonitor;
}

void Moniteur::setHighLimit(double NewLimit) {
    HighLimit = NewLimit;
}

void Moniteur::setAlarmStream(std::ostream &s) {
    alarmStream = &s;
}

void Moniteur::update(Capteur *SensorChanged) {
    std::cout << " " << std::endl;
    double Value = SensorChanged->getValue();
    lastValue[SensorChanged] = Value;
    histories[SensorChanged].push_front(Value);
    std::cout << "Etat " << currentState << std::endl;
    automaton[currentState]->SensorChange(SensorChanged);
}

void Moniteur::goToState(Moniteur::StateName s) {
    currentState = s;
    std::cout << "Etat " << currentState << std::endl;
}

std::ostream *Moniteur::getStream() {
    return (alarmStream);
}

double Moniteur::getLimit() {
    return HighLimit;
}

std::string Moniteur::getName() {
    if (Name != "unname") {
        return Name;
    }
    return std::to_string(reinterpret_cast<std::uintptr_t>(this));
}

void Moniteur::setName(std::string name) {
    Name = name;
}

void Moniteur::removeSensor(Capteur *s) {
    activeSensors.remove(s);
    s->removeObserver(this);
}

void Moniteur::setNmax(int newN) {
    Nmax = newN;
}

void Moniteur::reset() {
    currentState = NORMAL;
    activeSensors = Sensors;
    lastValue.clear();
    histories.clear();
    (*alarmStream) << "Reinitialisation" << std::endl;
    setupSensors(Sensors);
}
