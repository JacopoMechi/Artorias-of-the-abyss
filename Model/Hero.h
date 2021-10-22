#ifndef _HERO_H
#define _HERO_H

#include "GameCharacter.h"
#include "Inventory.h"
#include "Bonfire.h"



class Hero: public GameCharacter {
public: 

    Hero(int hp, int a, int c, int s, std::string& t, int d, int cd, float hPosX, float hPosY);
                                                    //d: dashCount, heroPosXY: heroPosXposY

    int getDash();
    void setDash(int dashCount);

    int getCooldown();
    void setCooldown(int cooldown);

    float getHeroPosX();
    void setHeroPosX(float heroPosX);

    float getHeroPosY();
    void setHeroPosY(float heroPosY);

    void dash(int dashCount, int cooldown);

    void addItem();
    
    void useItem();
    
    void switchZone();
    
    void useBonfire();

    void restoreHp(int amount);
    
/**
 * @param bool isKnight
 */
    void raiseShield(void bool isKnight);
    
/**
 * @param bool isMage
 * @param int cooldown
 */
    override attack(void bool isMage, void int cooldown);
    
    override movement();
    
    void respawn(float posX, float posY);
protected: 
    Inventory& inv;
    bool isMage;
    bool isKnight;
    int cooldown;
    Bonfire* bonfire ;
    int amount;
    int dashCount;
    float heroPosX;
    float heroPosY;
};

#endif //_HERO_H