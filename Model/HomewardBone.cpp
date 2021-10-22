#include "HomewardBone.h"

HomewardBone::HomewardBone(std::string n, int p, int c, std::string d, int M): Item(n, p, c, d, M){

}

HomewardBone::~HomewardBone(){

}

void HomewardBone::use(Hero& hero, MapElements& bonfire) {
    //if interaction
    hero.respawn(bonfire.getPosX()-2, bonfire.getPosY());
}