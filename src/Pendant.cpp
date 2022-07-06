#include "Pendant.h"

Pendant::Pendant(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                 sf::IntRect spriteRect, sf::IntRect effectRect): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, 
                 spriteRect, effectRect){
    sprite.setScale(2.1f, 2.1f);
    itemEffectSprite.setScale(6.5f, 6.5f);
}

Pendant::~Pendant(){

}

void Pendant::displayEffect(sf::Vector2f pos, sf::RenderWindow &window){
    if(!startEffect){
        pos.x -= 30;
        itemEffectSprite.setPosition(pos);
        window.draw(itemEffectSprite);
    }
}

void Pendant::use(Hero& hero) {//TODO implement hold time
    if(itemCount > 0){
        itemCount --;
        oldArmor = hero.getArmor();
        hero.setArmor(100);
        startEffect = false;
        startConsumable = false;
    }
}

void Pendant::consumableEffectTime(float dt, Hero &hero, sf::RenderWindow &window){
    if(!startConsumable){
        consumableTimeEffect += dt;
        if(consumableTimeEffect >= immuneTime){
            consumableTimeEffect = 0;
            hero.setArmor(oldArmor);
            startConsumable = true;
        }
    }
}