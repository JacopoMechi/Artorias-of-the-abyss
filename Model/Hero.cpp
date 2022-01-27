#include "Hero.h"

Hero::Hero(int hp, int armor, int cash, float movementSpeed, const sf::Vector2f& pos):
    GameCharacter(hp, armor, cash, movementSpeed, pos), leftWeapon(nullptr){
    //TODO implement a something that switch between mage and knight
}

Hero::~Hero(){
    if (leftWeapon != nullptr)
        delete leftWeapon;
}

int Hero::getDash(){
    return dashCount;
}
void Hero::setDash(int dashCount) {
    this -> dashCount = dashCount;
}

int Hero::getCooldown(){
    return cooldown;
}
void Hero::setCooldown(int cooldown) {
    this -> cooldown = cooldown;
}

void Hero::dash(int dashCount, int cooldown){
    //SFML if key is pressed reduce dashCount. When it reaches 0, start the cooldown
}

void Hero::restoreHp(int amount){
    //GameCharacter::setHp(GameCharacter::getHp+amount);
}

/*void Hero::useItem() {//TODO may be useful later

}*/

void Hero::switchZone() {//TODO useful later maybe

}

void Hero::useBonfire() {

}


void Hero::raiseShield(bool isKnight) {

}


/*void Hero::attack(bool isMage, int cooldown) {
    
}*/


void Hero::movement(bool isInventoryOpen){
    if (!isInventoryOpen){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            dir.y = -1.0f;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            dir.y = 1.0f;
        }else
        dir.y = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            dir.x = -1.0f;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            dir.x = 1.0f;
        }else
            dir.x = 0;

    }else
        dir = {0,0};
}


void Hero::respawn(float posX,float posY) {
    //finish hero
}

Weapon* Hero::getShield() {
    return leftWeapon;
}

void Hero::setShield(Weapon* leftWeapon) {
    this->leftWeapon = leftWeapon;
}