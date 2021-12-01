#include "EstusFlask.h"

EstusFlask::EstusFlask(std::string n, int p, std::string d, int M, int c): Item(n, p, d, M, c){

}

EstusFlask::~EstusFlask(){

}

void EstusFlask::use(Hero& hero) {//TODO reset usage in Bonfire
    if (EstusFlask::getItemCount() > 0)
        hero.restoreHp(healthRestored);
    EstusFlask::setItemCount(getItemCount()-1);
    //TODO something that blocks the hero
}