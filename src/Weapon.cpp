#include "Weapon.h"

int Weapon::getDamage() const{
    return damage;
}

int Weapon::getLevel() const{
    return level;
}

void Weapon::setLevel(int level){
    
}

void Weapon::setStartAnimation(bool startAnimation){
    this -> startAnimation = startAnimation;
}

sf::Sprite Weapon::getSprite() const{
    return weaponSprite;
}

void Weapon::use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt){
    
}

Weapon::Weapon(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level) : weaponRect(weaponRect), currentRect(weaponRect), nFrames(nFrames), level(level) {
    if(!texture.loadFromFile("Textures/Textures.png"))
        std::cout << "Error on loading weapon's texture" << std::endl;
    weaponSprite.setTexture(texture);
    weaponSprite.setTextureRect(weaponRect);
    weaponSprite.setScale(weaponScale);
}
