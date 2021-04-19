//
// Victor Perrin - Pierre Bando-Delaunay -- Mktro 2A
//

#include "StateAnomalie.h"

void StateAnomalie::SensorChange(Capteur *s) {
    std::cout <<"Anomalie" << std::endl;
    std::cout << monitor.getName() << ": le capteur a change : " << s->getName()
              << " nouvelle valeur : " << s->getValue() << std::endl;

    if ((*s).getValue() > monitor.getLimit()) {

        (*monitor.getStream()) <<"Anomalie du " << (*s).getName() << ", valeur  : "
                               << s->getValue() << std::endl;
        monitor.removeSensor(s);
        (*monitor.getStream()) <<"Suppression du " << std::endl;
        monitor.goToState(Moniteur::FAILURE);
        (*monitor.getStream()) << "Panne" << std::endl;
        (*monitor.getStream()) << "Nombre de capteurs actifs : " << monitor.activeSensors.size() << std::endl;
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

StateAnomalie::StateAnomalie(Moniteur &mon) : State(mon) {

}
