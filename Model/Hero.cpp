#include "Hero.h"

Hero::Hero(bool isKnight, int hp, int armor, int cash, float movementSpeed, const sf::Vector2f& pos):
    isKnight(isKnight), GameCharacter(hp, armor, cash, movementSpeed, pos){
    //TODO switch between mage and knight by checking isKnight
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


void Hero::raiseShield() {

}


void Hero::attack() {
    if(isKnight){
        //create texture rect and set nFrames
        if(dir.x > 0.0f){
            frameRect = {0, 158, 31, 22};
            lastActionFrame = frameRect;
        }else if(dir.x < 0.0f){    
            frameRect = {31, 158, -31, 22};
            lastActionFrame = frameRect;
        }else
            frameRect = lastActionFrame;
    }else{
        //same here but for the mage
    }
    actionStarting = true;
    iFrame = 0;
}

//handling character action inputs like attack, roll, interact
void Hero::updateInputs(sf::Event keyInput) {
    //for attacking
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::F)
        this -> attack();
    //for rolls
    //for using items in quickslot
}
void Hero::movement(bool isInventoryOpen){
    if (!isInventoryOpen && !actionStarting){

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