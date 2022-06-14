#include "HomewardBone.h"

HomewardBone::HomewardBone(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                           sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount,
                           spriteRect, effectRect){
    sprite.setScale(2.2f, 2.2f);
}

HomewardBone::~HomewardBone(){

}

void HomewardBone::use(Hero& hero) {//, MapElements& bonfire//TODO
   if(itemCount > 0){ 
       itemCount--;
        //if interaction
        //hero.respawn(bonfire.getPosX()-2, bonfire.getPosY());
   }
}