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
void setDamage(void int damage);
    
void getLevel();
    
/**
 * @param int level
 */
void setLevel(void int level);
    
void use();
    class Sword: public Weapon {
    };
    class Catalyst: public Weapon {
    };
    class Shield: public Weapon {
    public: 
        void defence;
        
void reduceDamage();
    };
protected: 
    int damage;
    int level;
};

#endif //_WEAPON_H