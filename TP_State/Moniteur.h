//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#pragma once

#include <list>
#include <iostream>
#include <map>
#include "Capteur.h"
#include "State.h"
#include <string>

class StateNormal;

class Capteur;

class State;

class StateAnomalie;

class StatePanne;

class Moniteur {
public:
    Moniteur();
    void setupSensors(std::list<Capteur *> &SensorsToMonitor);
    void setHighLimit(double NewLimit);
    void setAlarmStream(std::ostream &s);
    void update(Capteur *SensorChanged);
    void setName(std::string name);
    std::string getName();
    std::ostream *getStream();
    void removeSensor(Capteur *s);
    double getLimit();
    void reset();
    void setNmax(int newN);

private:
    std::string Name;
    std::list<Capteur *> Sensors;
    std::list<Capteur *> activeSensors;
    std::map<Capteur *, double> lastValue;
    std::map<Capteur *, std::list<double>> histories;
    double HighLimit;
    std::ostream *alarmStream;
    enum StateName {
        NORMAL, ANOMALY, FAILURE
    };
    State *automaton[sizeof(StateName)];
    StateName currentState;
    void goToState(StateName s);
    int Nmax;
    friend class StateNormal;
    friend class StateAnomalie;
    friend class StatePanne;
};


