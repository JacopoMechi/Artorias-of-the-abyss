#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include "MapElements.h"
#include "Weapon.h"

//TODO finish GameCharacter
class GameCharacter: public MapElements {
public:
    //GameCharacter();
    GameCharacter(int hp, int a, int c, int d, int s);//hp: HP, a: armor, c: cash, d: dashCount, s: speed
    ~GameCharacter();
    
    int getHp() const;//TODO is it necessary const?
    void setHp(int hp);
    
    int getArmor() const;//TODO is it necessary const?
    void setArmor(int armor);
    
    int getCash();
    void setCash(int cash);
    
    int getDash();
    void setDash(int dashCount);
    
    int getMovementSpeed(); const //TODO is it necessary const?
    void setMovementSpeed(int speed);
    
    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);
    
    void receiveDamage();
    
    Weapon* getShield();
    void setShield(Weapon* weapon);
    
    void isUnkillable();
    
    void isDialogue();
    
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
    Weapon* weapon;
    Weapon* leftWeapon;
};

#endif //_GAMECHARACTER_H