#include "HomewardBone.h"

HomewardBone::HomewardBone(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                           sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount,
                           spriteRect, effectRect){
    sprite.setScale(boneScale, boneScale);
}

HomewardBone::~HomewardBone(){

}

void HomewardBone::use(Hero& hero) {
    if(itemCount > 0){ 
        itemCount--;
        isRespawn = true;
    }
}