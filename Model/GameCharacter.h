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
    class Enemy: public GameCharacter {
    public: 
        
/**
 * @param float dropChance
 */
void dropItem(void float dropChance);
        
void getAggro();
        
/**
 * @param float aggroDistance
 */
void setAggro(void float aggroDistance);
        
/**
 * @param bool isRanged
 * @param int delay
 */
override attack(void bool isRanged, void int delay);
        
/**
 * @param isRanged
 */
override movement(void isRanged);
        
override respawn();
    protected: 
        bool isRanged;
        int delay;
        bool aggro;
        float dropChance;
        float aggroDistance;
    };
    class NPC: public GameCharacter {
    public: 
        
void sellItems();
    };
    class CharacterFactory {
    public: 
        
/**
 * @param characterType type
 */
void createCharacter(void characterType type);
    };
    class ItemFactory {
    public: 
        
/**
 * @param itemType type
 */
void createItem(void itemType type);
    };
protected: 
    int HP;
    int armor;
    int cash;
    int dashCount;
    int speed;
    Weapon* weapon;
};

#endif //_GAMECHARACTER_H