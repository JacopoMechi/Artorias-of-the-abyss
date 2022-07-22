#ifndef _GREENBLOSSOM_H
#define _GREENBLOSSOM_H

#include "Item.h"


class GreenBlossom: public Item {
public:
    explicit GreenBlossom(std::wstring itemName = L"Estratto di Fiore verde", int itemPrice = 1000,
                          std::wstring itemDescription = L"Riduce il cooldown \ndei dash per 60 secondi", int maxItemCount = 10, 
                          int itemCount = 0, sf::IntRect spriteRect = {blossomX, blossomY, blossomWidth, blossomHeight}, sf::IntRect effectRect = {blossomEffectX, blossomEffectY, blossomEffectWidth, blossomEffectHeight});
    virtual ~GreenBlossom();
    virtual void use(Hero &hero) override;
    virtual void consumableEffectTime(float dt, Hero &hero, sf::RenderWindow &window) override;
private:
    float oldCD = 0.0f;//tracking old cooldown value
    sf::Sprite arrowUp;//to display a visual effect that shows the effects of the item
};

#endif //_GREENBLOSSOM_H