#include "EstusFlask.h"

EstusFlask::EstusFlask(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, 
                       int itemCount, sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, 
                       itemPrice, itemDescription, maxItemCount, itemCount, spriteRect, effectRect){

}

EstusFlask::~EstusFlask(){

}

void EstusFlask::use(Hero& hero) {
    if (itemCount > 0){
        itemCount--;
        hero.setHp(hero.getHp()+healthRestored);
    }
}