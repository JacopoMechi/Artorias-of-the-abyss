#include "Pendant.h"

Pendant::Pendant(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                 sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, 
                 spriteRect, effectRect){
    sprite.setScale(2.1f, 2.1f);
}

Pendant::~Pendant(){

}

void Pendant::use(Hero& hero) {//TODO implement hold time
    if(itemCount > 0){
        itemCount --;
        int tmp = hero.getArmor();
        hero.setArmor(100);
        //wait 3 seconds with immuneTime
        hero.setArmor(tmp);
    }
}