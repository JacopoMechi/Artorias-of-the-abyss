#include "Hero.h"

Hero::Hero(bool isKnight, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed):
    isKnight(isKnight), GameCharacter(pos, hp, armor, cash, movementSpeed){
    if(!texture.loadFromFile("../Textures/Textures.png"))
        std::cout << "Error on loading hero's texture" << std::endl;
    sprite.setTexture(texture);//loading chracter's sprite
    //assigning weapon to hero
    //setting hero's sprite
    //this will be a default position with which the player will spawn
    if(isKnight){
        defaultRect = {0, 0, 16, 22};//for hero's sprite
        auraShield.setTexture(texture);//the aura shield is an exclusive of hero
        auraShield.setTextureRect({501, 124, 20, 26});
        auraShield.setScale(7.0f, 7.0f);
        canAttack = true;
        sword = std::make_unique<Sword>();//knight's weapon assign
    }else{
        defaultRect = {0, 83, 15, 21};
        canAttack = false;
        catalyst = std::make_unique<Catalyst>();//mage's weapon assign
    }
    frameRect = defaultRect; 
    sprite.setScale(7.5f, 7.5f);

}

int Hero::getDash() const{
    return dashCount;
}
void Hero::setDash(int dashCount)
{
    this->dashCount = dashCount;
}

void Hero::setDirX(float value){
    dir.x = value;
}

void Hero::setDirY(float value){
    dir.y = value;
}

int Hero::getCooldown() const{
    return dashTimeHolding;
}

void Hero::setCooldown(float dashTimeHolding)
{
    this->dashTimeHolding = dashTimeHolding;
}

bool Hero::getCharacterType() const{
    return isKnight;
}

bool Hero::getCanAttack() const{
    return canAttack;
}

void Hero::setCanAttack(bool canAttack){
    this -> canAttack = canAttack;
}

bool Hero::getStartingSpell() const{
    return startSpell;
}

bool Hero::getAuraReady() const{
    return auraReady;
}

void Hero::setAuraReady(bool auraReady)
{
    this->auraReady = auraReady;
}

int Hero::getMoneyAmount() const{
    return moneyCounter;
}

void Hero::setMoneyAmount(int moneyCounter){
    this -> moneyCounter = moneyCounter;
}

void Hero::dash()
{
    // for dashing, we just need to move the character position farther only in the moment that we press Space key
    dashing = dashDistance * dir;
    if (dashCount > 0)
    {
        dashCount--;
        pos += dashing;
    }
}

void Hero::blockDamage(sf::RenderWindow &window)
{
    auraShield.setPosition((pos.x - 10), (pos.y - 3)); //(pos.x+3), (pos.y+3)
    window.draw(auraShield);
}


void Hero::attack(sf::RenderWindow &window) {
    if(isKnight)
        sword -> use(window, frameRect, pos, delayTime);
    else{
        startSpell = catalyst -> getStartSpell();
        if(!startSpell)
            catalyst -> setSpellDirection(pos, frameRect);
        catalyst -> use(window, frameRect, pos, delayTime);
    }
}

void Hero::dealDamage(GameCharacter &entity){
    if(isKnight){
        if(sword -> getSprite().getGlobalBounds().intersects(entity.getSprite().getGlobalBounds()))
            entity.receiveDamage(sword -> getDamage());
    }else{
        if(catalyst -> getSprite().getGlobalBounds().intersects(entity.getSprite().getGlobalBounds()))
            entity.receiveDamage(catalyst -> getDamage());
    }
}

// handling character action inputs like attack, roll, interact
void Hero::updateDelay(float dt){
    // updating delay time
    delayTime = dt;
    
    //handling sword attack cooldown
    if(!canAttack && isKnight){
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

}

void Hero::setSpawnPoint(sf::Vector2f pos){
    respawnPos = pos;
}

sf::Vector2f Hero::getSpawnPoint() const{
    return respawnPos;
}

Weapon* Hero::getWeapon(){
    if(isKnight)
        return sword.get();
    else
        return catalyst.get();
}