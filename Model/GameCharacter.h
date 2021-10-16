#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include <string>
#include <iostream>
#include <complex> //for norm

#include "MapElements.h"
#include "Weapon.h"

//TODO finish GameCharacter
class GameCharacter: public MapElements {

public:
    GameCharacter(int hp, int a, int c, int d, int s, std::string& t);//hp: HP, a: armor, c: cash, d: dashCount, s: speed,
                                                                      //t: textPool
    ~GameCharacter();
    
    int getHp() const;
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

    //removed isUnkillable. In NPC use virtual void receiveDamage() override{};
    //removed respawn. I think its useless here. Better in Hero
    virtual void receiveDamage(int points);

    Weapon* getShield();
    void setShield(Weapon* weapon);
    
    void isDialogue();
    
    virtual void movement();
    
    void attack(GameCharacter &enemy);
    
    bool isChasing(int aggroDistance, const GameCharacter &enemy);
    
    void respawn();


protected: 
    int HP;
    int armor;
    int cash;
    int dashCount;
    int speed;
    int dialogueTracker = 0;
    Weapon* weapon;
    Weapon* leftWeapon;
    std::string& textPool;
};

#endif //_GAMECHARACTER_H