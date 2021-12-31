#include "EstusFlask.h"

EstusFlask::EstusFlask(std::string itemName, int itemPrice, std::string itemDescription,
                       int maxItemCount, int itemCount, int x, int y, int width, int height): 
                       Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, x, y, width, height){

}

EstusFlask::~EstusFlask(){

}

/*TODOvoid EstusFlask::use(Hero& hero) {reset usage in Bonfire
    if (EstusFlask::getItemCount() > 0)
        hero.restoreHp(healthRestored);
    EstusFlask::setItemCount(getItemCount()-1);
    // something that blocks the hero
}*/