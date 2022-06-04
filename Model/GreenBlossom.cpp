#include "GreenBlossom.h"

GreenBlossom::GreenBlossom(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                           sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, itemPrice, itemDescription, 
                           maxItemCount, itemCount, spriteRect, effectRect){

}

GreenBlossom::~GreenBlossom(){

}

void GreenBlossom::use(Hero& hero) {
    if(itemCount > 0){
        itemCount --;
        int tmp = hero.getCooldown();
        // for time = timeEffect in seconds
        hero.setCooldown(newCooldown);
        //end time
        hero.setCooldown(tmp);
        startEffect = false;
    }
}