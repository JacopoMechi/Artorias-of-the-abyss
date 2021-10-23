#ifndef ARTORIAS_OF_THE_ABYSS_GUARDIANSOUL_H
#define ARTORIAS_OF_THE_ABYSS_GUARDIANSOUL_H

#include "Item.h"

class GuardianSoul: public Item{
public:
    explicit GuardianSoul(std::string n = "Anima del Guardiano", int p = 0, std::string d = "Anima del leone alato bianco, "
                  "protettore del Santuario, che temeva la diffusione dell'Abisso.", int M = 1, int c = 0);
};

#endif //ARTORIAS_OF_THE_ABYSS_GUARDIANSOUL_H

