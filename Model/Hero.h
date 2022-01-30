#ifndef _HERO_H
#define _HERO_H

#include <string>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "Bonfire.h"



class Hero: public GameCharacter {
public: 

    Hero(bool isKnight, int hp, int armor, int cash, float movementSpeed, const sf::Vector2f& pos);
    ~Hero();

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

    void raiseShield();
    
    void attack();

    void updateInputs(sf::Event keyInput);
    
    void movement(bool isInventoryOpen);
    
    void respawn(float posX, float posY);

    Weapon* getShield();
    void setShield(Weapon* weapon);

protected: 

    int dialogueTracker = 0;
    bool isInventoryOpen;
    Weapon* leftWeapon;
    bool isKnight;
    int dashCount = 3;

    bool animationStarting = false;

    int cooldown = 5;
    Bonfire* bonfire ;
    int amount;
};

#endif //_HERO_H