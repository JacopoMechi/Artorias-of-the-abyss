#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include <string>
#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include "Rooms/RoomElement.h"
#include "Weapon.h"
#include "Sword.h"
#include "Catalyst.h"

class GameCharacter
{

public:
    GameCharacter(const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed);
    virtual ~GameCharacter() = default;

    int getHp() const;
    void setHp(int hp);

    sf::Vector2f getPos() const;
    void setPos(sf::Vector2f pos);

    int getArmor() const;
    void setArmor(int armor);

    int getCash() const;
    void setCash(int cash);

    int getMovementSpeed() const;
    void setMovementSpeed(int speed);

    virtual Weapon *getWeapon();

    virtual void receiveDamage(int points);

    virtual void movement(bool isInventoryOpen, bool isInteracting) = 0;
    
    virtual void attack(sf::RenderWindow& window);

    virtual void dealDamage(GameCharacter& entity);

    bool isAggro(float aggroDistance, GameCharacter &entity);

    void draw(sf::RenderWindow &window) const;

    void update(float dt);

    sf::Vector2f getSize() const;

    sf::Sprite getSprite() const;

protected:
    std::unique_ptr<Weapon> weapon;
    int HP;
    int armor;
    int cash;
    float movementSpeed;
    float aggroDistance;
    bool actionStarting = false;
    sf::Vector2f pos;
    sf::Vector2f vel = {0.0f, 0.0f};
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect frameRect;
    sf::IntRect defaultRect;//for resetting character in the right position
    GameCharacter* entityCollision;
    float animationHolding = 0.08f;// for max time cap
    int nFrames;
    int iFrame = 0;
    float animationTime = 0.0f;
    sf::Vector2f dir = {0.0f, 0.0f};
};

#endif //_GAMECHARACTER_H