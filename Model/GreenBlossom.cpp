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
        oldCD = hero.getCooldown();
        hero.setCooldown(newCooldown);
        startConsumable = false;
        startEffect = false;
    }
}

void GreenBlossom::consumableEffectTime(float dt, Hero &hero){
    if(!startConsumable){
        consumableTimeEffect += dt;
        if(consumableTimeEffect >= 2.0f){//2.0 is the effect time of the consumable
            consumableTimeEffect = 0;
            hero.setCooldown(oldCD);
            startConsumable = true;
        }
    }
}