#include "Hero.h"

Hero::Hero(bool isKnight, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed):
    isKnight(isKnight), GameCharacter(pos, hp, armor, cash, movementSpeed){
    //setting hero's sprite
    //this will be a default position with which the player will spawn
    if(isKnight)
        defaultRect = {0, 0, 16, 22};
    else
        defaultRect = {0, 83, 16, 21};
    lastFrameRect = defaultRect;//for updating the sprite
    frameRect = defaultRect; 
    texture.loadFromFile("../Textures/Textures.png");
    sprite.setTexture(texture);
    sprite.setScale(7.5f, 7.5f);
}

//Hero::~Hero(){//TODO
    //if (leftWeapon != nullptr)FIXME
    //    delete leftWeapon;
//}

int Hero::getDash(){
    return dashCount;
}
void Hero::setDash(int dashCount) {
    this -> dashCount = dashCount;
}

int Hero::getCooldown(){
    return dashTimeHolding;
}

void Hero::setCooldown(float dashTimeHolding){
    this -> dashTimeHolding = dashTimeHolding;
}

void Hero::dash(){
    //for dashing, we just need to move the character position farther only in the moment that we press Space key
    dashing = dashDistance*dir;
    if(dashCount > 0){
        dashCount --;
        pos += dashing; 
    }
}

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
    //for dash cooldown
    
    //handling dash cooldowns
    if(dashCount < maxDashes){
        dashTime += dt;
        if(dashTime >= dashTimeHolding){
            dashTime = 0;
            dashCount++;
        }
    }
}
void Hero::movement(bool isInventoryOpen, bool isInteracting){
    if (!isInventoryOpen && !isInteracting && !actionStarting){

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