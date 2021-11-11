#ifndef ARTORIAS_OF_THE_ABYSS_ARTORIASSOUL_H
#define ARTORIAS_OF_THE_ABYSS_ARTORIASSOUL_H

#include "Item.h"

class ArtoriasSoul: public Item{
public:
    explicit ArtoriasSoul(std::string n = "Anima di Artorias", int p = 0, std::string d = "Anima di un cavaliere valoroso,"
                  "che e' stato consumato dall'Abisso. La Leggenda narra che Artorias lo ha sconfitto, ma e' solo una "
                  "storia raccontata a meta'; sembra che sia stato sconfitto e il suo onore preservato da un eroe non "
                  "celebrato, il quale ha veramente sconfitto l'Abisso.", int M = 1, int c = 0);
};

#endif //ARTORIAS_OF_THE_ABYSS_ARTORIASSOUL_H

