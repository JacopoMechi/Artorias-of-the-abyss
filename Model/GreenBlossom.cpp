#include "GreenBlossom.h"

GreenBlossom::GreenBlossom(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                           sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, itemPrice, itemDescription, 
                           maxItemCount, itemCount, spriteRect, effectRect){
    arrowUp.setTexture(texture);
    arrowUp.setTextureRect({554, 0, 43, 63});
    arrowUp.setPosition({1700, 445});
    arrowUp.setScale(0.8f, 0.8f);
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

void GreenBlossom::consumableEffectTime(float dt, Hero &hero, sf::RenderWindow &window){
    if(!startConsumable){
        window.draw(arrowUp);
        consumableTimeEffect += dt;
        if(consumableTimeEffect >= 5.0f){//5.0 is the effect time of the consumable
            consumableTimeEffect = 0;
            hero.setCooldown(oldCD);
            startConsumable = true;
        }
    }
}