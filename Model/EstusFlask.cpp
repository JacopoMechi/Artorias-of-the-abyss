#include "EstusFlask.h"

EstusFlask::EstusFlask(std::string n, int p, int c, std::string d, int M): Item(n, p, c, d, M){

}

EstusFlask::~EstusFlask(){

}

int EstusFlask::getItemCount() {
    return itemCount;
}

void EstusFlask::setItemCount(int itemCount) {
    this -> itemCount = itemCount;
}

void EstusFlask::use(Hero& hero) {//TODO reset usage in Bonfire
    if (EstusFlask::getItemCount() > 0)
        hero.restoreHp(healthRestored);
    EstusFlask::setItemCount(getItemCount()-1);
    //TODO something that blocks the hero
}