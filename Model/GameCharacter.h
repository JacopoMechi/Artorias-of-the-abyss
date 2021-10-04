/**
 * Project Untitled
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include "MapElements.h"


class GameCharacter: public MapElements {
public: 
    
void getHp();
    
/**
 * @param int hp
 */
void setHp(void int hp);
    
void getArmor();
    
/**
 * @param int defence
 */
void setArmor(void int defence);
    
void getCash();
    
/**
 * @param int cash
 */
void setCash(void int cash);
    
void getDash();
    
/**
 * @param int dashCount
 */
void setDash(void int dashCount);
    
void getMovementSpeed();
    
/**
 * @param int speed
 */
void setMovementSpeed(void int speed);
    
void getWeapon();
    
/**
 * @param Weapon* weapon
 */
void setWeapon(void Weapon* weapon);
    
void receiveDamage();
    
void getShield();
    
void setShield();
    
void isUnkillable();
    
void isDialogue();
    
void movement();
    
void attack();
    
void isChasing();
    
void respawn();
protected: 
    int HP;
    int armor;
    int cash;
    int dashCount;
    int speed;
    Weapon* weapon;
};

#endif //_GAMECHARACTER_H