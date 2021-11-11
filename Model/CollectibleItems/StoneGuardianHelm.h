#ifndef ARTORIAS_OF_THE_ABYSS_STONEGUARDIANHELM_H
#define ARTORIAS_OF_THE_ABYSS_STONEGUARDIANHELM_H

#include "Item.h"

class StoneGuardianHelm: public Item{
public:
    explicit StoneGuardianHelm(std::string n = "Elmo del Guardiano di Pietra", int p = 0, std::string d = "Elmo indossato dai "
                      "Guardiani di Pietra. In realta', questi nemici sono un'armatura animata, armati di un'Ascia di "
                      "Pietra, ma senza uno scudo.", int M = 1, int c = 0);
};

#endif //ARTORIAS_OF_THE_ABYSS_STONEGUARDIANHELM_H
