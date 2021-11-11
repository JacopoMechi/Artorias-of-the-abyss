#ifndef ARTORIAS_OF_THE_ABYSS_MANUSSOUL_H
#define ARTORIAS_OF_THE_ABYSS_MANUSSOUL_H

#include "Item.h"

class ManusSoul: public Item{
public:
    explicit ManusSoul(std::string n = "Anima di Manus", int p = 0, std::string d = "Anima di Manus, Padre dell'Abisso. "
              "Chiaramente, una volta era essere umano che, a causa della perdita di un oggetto a lui caro, un pendente,"
              " che lo porto' alla follia, divenne Padre dell'Abisso", int M = 1, int c = 0);
};

#endif //ARTORIAS_OF_THE_ABYSS_MANUSSOUL_H
