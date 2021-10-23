#ifndef ARTORIAS_OF_THE_ABYSS_OOLACILERESIDENTHEAD_H
#define ARTORIAS_OF_THE_ABYSS_OOLACILERESIDENTHEAD_H

#include "Item.h"

class OolacileResidentHead: public Item{
public:
    explicit OolacileResidentHead(std::string n = "Elmo del Cittadino di Oolacile", int p = 0, std::string d = "Creature"
                                  " umanoidi corrotte dall'Abisso. Sono caratterizzati da lunghe braccia e da una "
                                  "testa gonfia, piena di occhi di colore rosso.", int M = 1, int c = 0);
};

#endif //ARTORIAS_OF_THE_ABYSS_OOLACILERESIDENTHEAD_H
