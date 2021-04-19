//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include <cfloat>
#include "StateNormal.h"

void StateNormal::SensorChange(Capteur *s) {
    if (s->getValue() > max_sensor) {
        max_sensor = s->getValue();
    }
    if (s->getValue() < min_sensor) {
        min_sensor = s->getValue();
    }
    std::cout << monitor.getName() << ": le " << s->getName() << " a change, nouvelle valeur: "
              << s->getValue() << std::endl;
    std::cout << "Valeurs maxi: " << max_sensor << ", mini: " << min_sensor << std::endl;

    if ((*s).getValue() > monitor.getLimit()) {
        (*monitor.getStream()) << "Anomalie dans le " << (*s).getName() << std::endl;
        monitor.removeSensor(s);
        (*monitor.getStream()) << "Suppression du capteur dans le moniteur" << std::endl;
        std::cout << "Capteur actifs : " << monitor.activeSensors.size() << std::endl;
        if (!monitor.activeSensors.empty()) {
            monitor.goToState(Moniteur::ANOMALY);
            (*monitor.getStream()) << "Anomalie" << std::endl;
        } else {
            monitor.goToState(Moniteur::FAILURE);
            (*monitor.getStream()) << "Panne" << std::endl;
            (*monitor.getStream()) << "Capteur actifs : " << monitor.activeSensors.size() << std::endl;
            for (auto it = monitor.histories.cbegin(); it != monitor.histories.cend(); it++) {
                (*monitor.getStream()) << (it->first)->getName() << ":" << std::endl;
                int iter = 0;
                for (auto it_liste = (it->second).cbegin(); it_liste != (it->second).cend(); it_liste++) {
                    if (iter < monitor.Nmax and iter < (it->second).size()) {
                        iter++;
                    }
                }
            }
        }
    }
}

StateNormal::StateNormal(Moniteur &mon) : State(mon), min_sensor(DBL_MAX), max_sensor(DBL_MIN) {

}

StateNormal::~StateNormal() {}