#include "ItemFactory.h"

Item* ItemFactory::createItem(std::string type) const {
    Item* item = 0;
    if(type.compare("guardianSoul"))
        item = new GuardianSoul();
    else if(type.compare("artoriasSoul"))
        item = new ArtoriasSoul();
    else if(type.compare("manusSoul"))
        item = new ManusSoul();
    else if(type.compare("humanity"))
        item = new Humanity();
    else if(type.compare("oolacileResidentHead"))
        item = new OolacileResidentHead();
    else if(type.compare("oolacileSorcererHead"))
        item = new OolacileSorcererHead();
    else if(type.compare("stoneGuardianHelm"))
        item = new StoneGuardianHelm();
    return item;
}