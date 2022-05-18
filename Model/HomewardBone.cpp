#include "HomewardBone.h"

HomewardBone::HomewardBone(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount,
                           int x, int y, int width, int height): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount,
                           x, y, width, height){

}

HomewardBone::~HomewardBone(){

}

/*void HomewardBone::use(Hero& hero, MapElements& bonfire) {//TODO
    //if interaction
    hero.respawn(bonfire.getPosX()-2, bonfire.getPosY());
}*/