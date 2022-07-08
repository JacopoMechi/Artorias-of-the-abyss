#include "Weapon.h"

int Weapon::getDamage()
{
    return damage;
}

int Weapon::getLevel()
{
    return level;
}

Weapon::Weapon(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level) : nFrames(nFrames), level(level) {
    if(!texture.loadFromFile("../Textures/Textures.png"))
        std::cout << "Error on loading weapon's texture" << std::endl;
    weaponSprite.setTexture(texture);
    weaponSprite.setTextureRect(weaponRect);
    weaponSprite.setScale(weaponScale);
}
