#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include <string>
#include <iostream>
#include <complex> //for norm

#include <SFML/Graphics.hpp>
#include "MapElements.h"
#include "Weapon.h"

class GameCharacter:  public MapElements{

public:
    
    GameCharacter(int hp, int a, int c, int mS, const sf::Vector2f& pos);
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
    
    void applyToSprite(sf::Sprite& s) const;
    
    void update(float dt);

   void animation(int x, int y, int width, int height, bool isLeft);

   void adjourn(float dt);

protected: 
    int HP;
    int armor;
    int cash;
    int movementSpeed;
    int dialogueTracker = 0;
    int x;
    int y;
    int width;
    int height;
    bool isLeft;
    Weapon* weapon;
    Weapon* leftWeapon;
    enum class AnimationIndex{
        WalkingLeft,
        WalkingRight,
        Count
    };
    static constexpr float speed = 100.0f;
    sf::Vector2f pos;
    sf::Vector2f vel = {0.0f, 0.0f};
    sf::Sprite sprite;
    sf::Texture texture;
    AnimationIndex curAnimation = AnimationIndex::WalkingRight;
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