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

void Hero::dash(){
    //for dashing, we just need to move the character position farther only in the moment that we press Space key
    dashing = dashDistance*dir;
    dashCount --;
    //handling dash cooldowns
    if(dashCount < 3){
        dashTime += delayTime;
        if(dashTime >= dashTimeHolding){
            dashTime = 0;
            dashCount ++;
        }
    }
    if(dashCount > 0)
        pos += dashing; 
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
void Hero::updateDelayAndInputs(sf::Event keyInput, float dt) {
    //updating delay time
    delayTime = dt;
    //for attacking
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::F)
        this -> attack();
    //for dashes
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Space)
        this -> dash();
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