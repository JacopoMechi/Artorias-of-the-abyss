#ifndef _NPC_H
#define _NPC_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <fstream>

#include "GameCharacters/GameCharacter.h"
#include "Items/Item.h"
#include "GameCharacters/Hero.h"
#include "Items/HomewardBone.h"
#include "Items/Pendant.h"
#include "Items/GreenBlossom.h"

class NPC : public GameCharacter
{

public:
    explicit NPC(sf::RenderWindow &window, int type, const sf::Vector2f &pos, int hp = 100, int armor = 0, int cash = 0, float movementSpeed = 0);
    virtual ~NPC() = default;

    // disabling inherited methods
    virtual void receiveDamage(int points) override; // to be unkillable
    virtual void attack(sf::RenderWindow &window) override;
    virtual void movement(bool isInventoryOpen, bool isInteracting) override;

    // to know if hero is close to npcs
    bool closeToHero(Hero &hero);

    // method to let HUD get text pool
    std::vector<std::wstring> getTextPool() const;

    // getter NPC information for HUD purpose
    int getNPCType() const;

private:
    //opening txt for dialogues
    std::wfstream poolPhrases;
    std::wstring string;

    // loading hud textures
    sf::Texture hudTexture;

    // for tracking character type
    int type;

    // setting textpool for dialogues depending on character
    std::vector<std::wstring> textPool;
};

#endif