#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include <string>
#include <iostream>

#include "MapElements.h"
#include "Weapon.h"

//TODO finish GameCharacter
class GameCharacter: public MapElements {

public:
    GameCharacter(int hp, int a, int c, int d, int s);//hp: HP, a: armor, c: cash, d: dashCount, s: speed,
                                                              //di: dialoguetext
    ~GameCharacter();
    
    int getHp() const;//const for more reliable and safe code
    void setHp(int hp);
    
    int getArmor() const;
    void setArmor(int armor);
    
    int getCash() const;
    void setCash(int cash);
    
    int getDash() const;
    void setDash(int dashCount);
    
    int getMovementSpeed()const;
    void setMovementSpeed(int speed);
    
    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);
    
    void receiveDamage();
    
    Weapon* getShield();
    void setShield(Weapon* weapon);
    
    void isUnkillable();
    
    static void isDialogue(int voiceLine);
    
    virtual void movement();
    
    void attack();
    
    void isChasing();
    
    void respawn();


protected: 
    int HP;
    int armor;
    int cash;
    int dashCount;
    int speed;
    int voiceLine;
    Weapon* weapon;
    Weapon* leftWeapon;
};

#endif //_GAMECHARACTER_H