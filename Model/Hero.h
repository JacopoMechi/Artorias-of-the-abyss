#ifndef _HERO_H
#define _HERO_H

#include <string>
#include <cmath>
#include <iostream>

#include "GameCharacter.h"
#include "Bonfire.h"



class Hero: public GameCharacter {
public: 

    Hero(int hp, int armor, int cash, float movementSpeed, const sf::Vector2f& pos, int dashCount, int cooldown);

    int getDash();
    void setDash(int dashCount);

    int getCooldown();
    void setCooldown(int cooldown);

    float getHeroPosY();
    void setHeroPosY(float heroPosY);

    void dash(int dashCount, int cooldown);

    void addItem();
    
    void useItem();
    
    void switchZone();
    
    void useBonfire();

    void restoreHp(int amount);

    void raiseShield(bool isKnight);
    
    //override attack(void bool isMage, void int cooldown);
    
    void movement(bool isInventoryOpen);
    
    void respawn(float posX, float posY);

protected: 

    
    bool isMage;
    bool isKnight;
    int cooldown;
    Bonfire* bonfire ;
    int amount;
    int dashCount;
};

#endif //_HERO_H