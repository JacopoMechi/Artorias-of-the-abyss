#ifndef _ITEMFACTORY_H
#define _ITEMFACTORY_H

#include "Item.h"
#include "CollectibleItems/GuardianSoul.h"
#include "CollectibleItems/ArtoriasSoul.h"
#include "CollectibleItems/ManusSoul.h"
#include "CollectibleItems/Humanity.h"
#include "CollectibleItems/StoneGuardianHelm.h"
#include "CollectibleItems/OolacileResidentHead.h"
#include "CollectibleItems/OolacileSorcererHead.h"

enum class ItemType {GuardianSoul, ArtoriasSoul, ManusSoul, StoneGuardianHead, OolacileResidentHead,
        OolacileSorcererHead, Humanity};

class ItemFactory {
public:
    Item* createItem(std::string type) const;
};

#endif //_ITEMFACTORY_H