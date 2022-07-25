#include "NPC.h"

NPC::NPC(sf::RenderWindow &window, int type, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : type(type), GameCharacter(window, pos, hp, armor, cash, movementSpeed)
{
    // loading NPC's texture
    if (!texture.loadFromFile(texturePath))
        std::cout << "Error on loading npc's texture" << std::endl;
    sprite.setTexture(texture);
    // setting NPC's scale
    sprite.setScale(npcScale, npcScale);
    // setting NPC's position
    sprite.setPosition(pos);
    //opening text file for dialogue pools
    poolPhrases.open("npcDialogues.txt", std::ios::in);
    // loading npcs sprites' rectangles
    // chester
    if (type == 0)
    {
        defaultRect = {chesterX, chesterY, chesterWidth, chesterHeight};

        // chester's dialogue
        if(poolPhrases.is_open()){
            for(int line = 0; std::getline(poolPhrases, string) && line <= chesterPoolEnd; line++){
                if(line >= chesterPoolBegin)
                    textPool.push_back(string);
            }
        }
        // elizabeth
    }
    else if (type == 1)
    {
        defaultRect = {elizabethX, elizabethY, elizabethWidth, elizabethHeight};

        // elizabeth's dialogue
        if(poolPhrases.is_open()){
            for(int line = 0; std::getline(poolPhrases, string) && line <= elizabethPoolEnd; line ++){
                if(line >= elizabethPoolBegin)
                    textPool.push_back(string);
            }
            poolPhrases.close();
        }
        // dusk
    }
    else if (type == 2)
    {
        defaultRect = {duskX, duskY, duskWidth, duskHeight};

        // dusk's dialogue
        if(poolPhrases.is_open()){
            for(int line = 0; std::getline(poolPhrases, string) && line <= duskPoolEnd; line ++){
                if(line >= duskPoolBegin)
                    textPool.push_back(string);
            }
        }
        // sif
    }
    else if (type == 3)
    {
        defaultRect = {sifX, sifY, sifWidth, sifHeight};
    }
    else
        std::cout << "Error on loading NPC type" << std::endl;
    frameRect = defaultRect;
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
    if (isAggro(heroNpcDistance, hero))
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