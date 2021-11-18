#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include <string>
#include <iostream>
#include <complex> //for norm

#include "Graphics.hpp"
#include "MapElements.h"
#include "Weapon.h"
#include "Animation.h"

class GameCharacter:  public MapElements{

public:
    GameCharacter(int hp, int a, int c, int mS);//hp: HP, a: armor, c: cash, mS: movementSpeed, t: textPool
    GameCharacter(const sf::Vector2f& pos,sf::Texture texture, float rectPosX, float rectPosY, float rectWidth, float rectHeight);
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
    
    void applyToSprite(sf::Sprite& s) const;
    
    void update(float dt);

protected: 
    int HP;
    int armor;
    int cash;
    int movementSpeed;
    int dialogueTracker = 0;
    float rectPosX;
    float rectPosY;
    float rectWidth;
    float rectHeight;
    Weapon* weapon;
    Weapon* leftWeapon;

    sf::Texture texture;
    enum class AnimationIndex{
        WalkingUp,
        WalkingDown,
        WalkingLeft,
        WalkingRight,
        Idle,
        Count
    };
    static constexpr float speed = 100.0f;
    sf::Vector2f pos;
    sf::Vector2f vel = {0.0f, 0.0f};
    sf::Sprite sprite;
    Animation animations[int(AnimationIndex::Count)];
    AnimationIndex curAnimation = AnimationIndex::Idle;
    void advance(){
        if (++iFrame >= nFrames)
            iFrame = 0;
    }
    static constexpr int nFrames = 5;
    static constexpr float holdTime = 0.01f;
    sf::IntRect frames[nFrames];
    int iFrame = 0;
    float time = 0.0f;

};

#endif //_GAMECHARACTER_H