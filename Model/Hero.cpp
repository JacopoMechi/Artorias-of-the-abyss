#include "Hero.h"

Hero::Hero(bool isKnight, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed):
    isKnight(isKnight), GameCharacter(pos, hp, armor, cash, movementSpeed){
    texture.loadFromFile("../Textures/Textures.png");
    sprite.setTexture(texture);//loading chracter's sprite
    weaponAttack.setTexture(texture);//loading character's weapon
    //setting hero's sprite
    //this will be a default position with which the player will spawn
    if(isKnight){
        defaultRect = {0, 0, 16, 22};
        auraShield.setTexture(texture);
        auraShield.setTextureRect({501, 124, 20, 26});
        auraShield.setScale(7.0f, 7.0f);
        weaponRect = {3, 157, 21, 44};
        weaponAttack.setScale(7.5f, 7.5f);
        nWeaponFrames = 5;
    }else
        defaultRect = {0, 83, 15, 21};
    weaponAttack.setTextureRect(weaponRect);
    frameRect = defaultRect; 
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

bool Hero::getCanAttack(){
    return canAttack;
}

void Hero::setCanAttack(bool canAttack){
    this -> canAttack = canAttack;
}

bool Hero::getAuraReady(){
    return auraReady;
}

void Hero::setAuraReady(bool auraReady){
    this -> auraReady = auraReady;
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


void Hero::blockDamage(sf::RenderWindow &window) {
    auraShield.setPosition((pos.x-10), (pos.y-3));//(pos.x+3), (pos.y+3)
    window.draw(auraShield);
}


void Hero::attack(sf::RenderWindow &window) {
    if(!canAttack){
        //setting position and rectangles of the weapon
        if(isKnight){
            if(dir.x > 0.0f){
                currentRect = weaponRect;
                xVariation = 100;
            }else if(dir.x < 0.0f){
                currentRect = {weaponRect.left, weaponRect.top, -weaponRect.width, weaponRect.height};
                xVariation = -120;
            }    
        }

        //updating iFrames for weapon
        weaponAnimationTime += delayTime;
        if(weaponAnimationTime >= weaponAnimationHolding){
            iWeaponFrame = (++iWeaponFrame) % nWeaponFrames;
            weaponAnimationTime = 0.0f;
            if(iWeaponFrame == 0)
                canAttack = true;
            //starting attack cooldown//FIXME
        }

        //drawing animation
        if(!canAttack){
            weaponAttack.setPosition(pos.x+xVariation, pos.y-50);
            weaponAttack.setTextureRect({currentRect.left + iWeaponFrame*abs(currentRect.width), currentRect.top, currentRect.width, currentRect.height});
            window.draw(weaponAttack);
        }
    }
}

//handling character action inputs like attack, roll, interact
void Hero::updateDelayAndInputs(sf::Event keyInput, float dt) {
    //updating delay time
    delayTime = dt;
    
    //handling attack cooldown
    if(!canAttack){
        attackTime += delayTime;
        if(attackTime >= attackTimeHolding){
            attackTime = 0;
            canAttack = true;
        }
    }

    //handling shield aura time
    if(!auraReady){
        auraTime += delayTime;
        if(auraTime >= auraTimeHolding){//TODO or when character got hit
            auraTime = 0;
            auraReady = true;
        }
    }

    //handling dash cooldown
    if(dashCount < maxDashes){
        dashTime += delayTime;
        if(dashTime >= dashTimeHolding){
            dashTime = 0;
            dashCount++;
        }
    }
}
void Hero::movement(bool isInventoryOpen, bool isInteracting){
    if (!isInventoryOpen && !isInteracting){

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
