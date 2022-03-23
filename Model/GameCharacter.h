#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include <string>
#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include "MapElement.h"
#include "Weapon.h"

class GameCharacter{//:  public MapElement

public:
    
    GameCharacter(const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed);           
    virtual ~GameCharacter() = default;
    
    int getHp() const;
    void setHp(int hp);
    
    sf::Vector2f getPos() const;
    void setPos (sf::Vector2f pos);
    
    int getArmor() const;
    void setArmor(int armor);
    
    int getCash() const;
    void setCash(int cash);
    
    int getMovementSpeed()const;
    void setMovementSpeed(int speed);
    
    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);

    virtual void receiveDamage(int points);

    //virtual void movement() = 0;//in commit add "movement and attack, in gamecharacter class, are now base methods"
    
    virtual void attack();
    
    bool isAggro(float aggroDistance, GameCharacter &entity);

    void draw(sf::RenderTarget &rt) const;
    
    void update(float dt);

protected: 
    int HP;
    int armor;
    int cash;
    float movementSpeed;
    float aggroDistance;
    bool actionStarting = false;
    Weapon* weapon;
    sf::Vector2f pos;
    sf::Vector2f vel = {0.0f, 0.0f};
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect frameRect = {0, 0, 16, 22};
    sf::IntRect lastFrameRect = {0, 0, 16, 22};
    float animationHolding = 0.08f;// for max time cap
    int nFrames;
    int iFrame = 0;
    float animationTime = 0.0f;
    sf::Vector2f dir = {0.0f, 0.0f};
};

#endif //_GAMECHARACTER_H