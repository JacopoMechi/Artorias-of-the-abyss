#include "Spell.h"

Spell::Spell(const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed): GameCharacter(pos, hp, armor, cash, movementSpeed){
    texture.loadFromFile("../Textures/Textures.png");
    sprite.setTexture(texture);
    sprite.setTextureRect({3, 299, 33, 20});
}

void Spell::receiveDamage(int points){

}

void Spell::attack(sf::RenderWindow &window){

}

void Spell::movement(bool isInventoryOpen, bool isInteracting){
    
}