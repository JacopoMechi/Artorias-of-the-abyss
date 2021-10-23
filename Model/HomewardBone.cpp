#include "HomewardBone.h"

HomewardBone::HomewardBone(std::string n, int p, std::string d, int M, int c): Item(n, p, d, M, c){

}

HomewardBone::~HomewardBone(){

}

void HomewardBone::use(Hero& hero, MapElements& bonfire) {
    //if interaction
    hero.respawn(bonfire.getPosX()-2, bonfire.getPosY());
}