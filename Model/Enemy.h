/**
 * Project Untitled
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameCharacter.h"


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

#endif //_ENEMY_H