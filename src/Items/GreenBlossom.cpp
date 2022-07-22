#include "GreenBlossom.h"

GreenBlossom::GreenBlossom(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                           sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, itemPrice, itemDescription, 
                           maxItemCount, itemCount, spriteRect, effectRect){
    arrowUp.setTexture(texture);
    arrowUp.setTextureRect({arrowUpX, arrowUpY, arrowUpWidth, arrowUpHeight});
    arrowUp.setPosition({arrowUpPosX, arrowUpPosY});
    arrowUp.setScale(arrowUpScale, arrowUpScale);
}

GreenBlossom::~GreenBlossom(){

}

void GreenBlossom::use(Hero& hero) {
    if(itemCount > 0){
        itemCount --;
        oldCD = hero.getCooldown();
        hero.setCooldown(blossomCooldown);
        startConsumable = false;
        startEffect = false;
    }
}

void GreenBlossom::consumableEffectTime(float dt, Hero &hero, sf::RenderWindow &window){
    if(!startConsumable){
        window.draw(arrowUp);
        consumableTimeEffect += dt;
        if(consumableTimeEffect >= blossomEffectTime){
            consumableTimeEffect = 0;
            hero.setCooldown(oldCD);
            startConsumable = true;
        }
    }
}