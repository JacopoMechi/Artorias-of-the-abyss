/**
 * Project Untitled
 */


#ifndef _HERO_H
#define _HERO_H

#include "GameCharacter.h"


class Hero: public GameCharacter {
public: 
    
/**
 * per drop e shop
 */
void addItem();
    
void useItem();
    
void switchZone();
    
void useBonfire();
    
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
    
override respawn();
protected: 
    Inventory& inv;
    bool isMage;
    bool isKnight;
    void cooldown;
    Bonfire* bonfire ;
};

#endif //_HERO_H