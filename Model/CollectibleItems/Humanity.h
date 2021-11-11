#ifndef ARTORIAS_OF_THE_ABYSS_HUMANITY_H
#define ARTORIAS_OF_THE_ABYSS_HUMANITY_H

#include "Item.h"

class Humanity: public Item{
public:
    explicit Humanity(std::string n = "Umanita'", int p = 0, std::string d = "Questi fantasmi sono una rappresentazione "
             "dell'umanita' come un'entita' non ancora formatasi, usata dagli Stregoni di Oolacile per castare "
             "le loro stregonerie. A differenza degli altri nemici, non hanno alcun attacco e danneggiano solo "
             "attraverso il contatto fisico.", int M = 1, int c = 0);
};

#endif //ARTORIAS_OF_THE_ABYSS_HUMANITY_H
