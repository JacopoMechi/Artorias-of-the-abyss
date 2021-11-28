#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include <string>
#include <iostream>
#include <complex> //for norm

#include <SFML/Graphics.hpp>
#include "MapElement.h"
#include "Weapon.h"

class GameCharacter{//:  public MapElement

public:
    
    GameCharacter(int hp, int a, int c, float mS, const sf::Vector2f& pos);
    //hp: HP, a: armor, c: cash, mS: movementSpeed, t: textPool               
    ~GameCharacter();
    
    int getHp() const;
    void setHp(int hp);
    
    int getArmor() const;
    void setArmor(int armor);
    
    int getCash() const;
    void setCash(int cash);
    
    int getMovementSpeed()const;
    void setMovementSpeed(int speed);
    
    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);

    //removed isUnkillable. In NPC use virtual void receiveDamage() override{};
    //removed respawn. I think its useless here. Better in Hero
    virtual void receiveDamage(int points);

    Weapon* getShield();
    void setShield(Weapon* weapon);
    
    virtual void movement();
    
    virtual void attack(GameCharacter &opponent);
    
    bool isChasing(int aggroDistance, const GameCharacter &enemy);

    void draw(sf::RenderTarget& rt) const;

    void setDirection(const sf::Vector2f& dir);
    
    void update(float dt);

    void animation(int x, int y, int width, int height, bool isLeft, bool isIdle);

protected: 
    int HP;
    int armor;
    int cash;
    float movementSpeed;
    int dialogueTracker = 0;
    int x;
    int y;
    int width;
    int height;
    bool isLeft;
    bool isIdle;
    Weapon* weapon;
    Weapon* leftWeapon;
    enum class AnimationIndex{
        WalkingLeft,
        WalkingRight,
        IdleLeft,
        IdleRight,
        Count
    };
    sf::Vector2f pos;
    sf::Vector2f vel = {0.0f, 0.0f};
    sf::Sprite sprite;
    sf::Texture texture;
    AnimationIndex lastAnimation = AnimationIndex::IdleRight;
    void advance(){
        if (++iFrame >= nFrames)
            iFrame = 0;
    }
    static constexpr int nFrames = 8;
    static constexpr float holdTime = 0.1f;
    sf::IntRect frames[nFrames];
    int iFrame = 0;
    float time = 0.0f;
};

#endif //_GAMECHARACTER_H