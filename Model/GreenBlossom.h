#ifndef _GREENBLOSSOM_H
#define _GREENBLOSSOM_H

#include "Item.h"


class GreenBlossom: public Item {
public:
    explicit GreenBlossom(std::wstring itemName = L"Estratto di Fiore verde", int itemPrice = 1000,
                          std::wstring itemDescription = L"Riduce il cooldown \ndei dash per 60 secondi", int maxItemCount = 10, 
                          int itemCount = 0, sf::IntRect spriteRect = {453, 2, 20, 20}, sf::IntRect effectRect = {530, 124, 17, 22});
    virtual ~GreenBlossom();
    virtual void use(Hero &hero) override;
    virtual void consumableEffectTime(float dt, Hero &hero) override;
private:
    float newCooldown = 1.0f;// TODO needs to be balanced
    int timeEffect = 60;
    float oldCD = 0.0f;//tracking old cooldown value
};

#endif //_GREENBLOSSOM_H