#ifndef ARTORIAS_OF_THE_ABYSS_OOLACILESORCERERHEAD_H
#define ARTORIAS_OF_THE_ABYSS_OOLACILESORCERERHEAD_H

#include "Item.h"

class OolacileSorcererHead: public Item{
public:
    explicit OolacileSorcererHead(std::string n = "Elmo dello Stregone di Oolacile", int p = 0, std::string d = "Creature "
                                  "che somigliano ai Cittadini di Oolacile, ma indossano abitano neri lacerati e "
                                  "brandiscono un Catalizzatore di Oolacile.", int M = 1, int c = 0);
};

#endif //ARTORIAS_OF_THE_ABYSS_OOLACILESORCERERHEAD_H
