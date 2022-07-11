#include "NPC.h"

NPC::NPC(sf::RenderWindow &window, int type, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : type(type), GameCharacter(window, pos, hp, armor, cash, movementSpeed)
{
    // loading NPC's texture
    if (!texture.loadFromFile(texturePath))
        std::cout << "Error on loading npc's texture" << std::endl;
    sprite.setTexture(texture);
    // setting NPC's scale
    sprite.setScale(5.0f, 5.0f);
    // setting NPC's position
    sprite.setPosition(pos);
    // loading npcs sprites' rectangles
    // chester
    if (type == 0)
    {
        defaultRect = {394, 22, 16, 14};

        // chester's dialogue
        textPool.resize(sizeof(chesterPool) / sizeof(std::string));
        textPool.insert(textPool.begin(), &chesterPool[0], &chesterPool[sizeof(chesterPool) / sizeof(std::string)]);
        // elizabeth
    }
    else if (type == 1)
    {
        defaultRect = {393, 40, 22, 25};

        // elizabeth's dialogue
        textPool.resize(sizeof(elizabethPool) / sizeof(std::string));
        textPool.insert(textPool.begin(), &elizabethPool[0], &elizabethPool[(sizeof(elizabethPool) / sizeof(std::string))]);
        // dusk
    }
    else if (type == 2)
    {
        defaultRect = {422, 35, 23, 30};

        // dusk's dialogue
        textPool.resize(sizeof(duskPool) / sizeof(std::string));
        textPool.insert(textPool.begin(), &duskPool[0], &duskPool[sizeof(duskPool) / sizeof(std::string)]);
        // sif
    }
    else if (type == 3)
    {
        defaultRect = {452, 38, 25, 27};
    }
    else
        std::cout << "Error on loading NPC type" << std::endl;
    sprite.setTextureRect(defaultRect);
}

void NPC::receiveDamage(int points)
{
    std::cout << "Error: cannot use receiveDamage function in NPC class" << std::endl;
}

void NPC::attack(sf::RenderWindow &window)
{
    std::cout << "Error: cannot use attack function in NPC class" << std::endl;
}

void NPC::movement(bool isInvetoryOpen, bool isInteracting)
{
    std::cout << "Error: cannot use movement function in NPC class" << std::endl;
}

bool NPC::closeToHero(Hero &hero)
{
    if (isAggro(190, hero))
        return true;
    else
        return false;
}

std::vector<std::wstring> NPC::getTextPool() const
{
    return textPool;
}

int NPC::getNPCType() const
{
    return type;
}