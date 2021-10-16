/**
 * Project Untitled
 */


#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon {
public: 
    
void getDamage();
    
/**
 * @param int damage
 */
void setDamage(int damage);
    
void getLevel();
    
/**
 * @param int level
 */
void setLevel(int level);
    
virtual int use() = 0;

protected: 
    int damage;
    int level;
};

#endif //_WEAPON_H