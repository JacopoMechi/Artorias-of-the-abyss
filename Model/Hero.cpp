#include "Hero.h"

Hero::Hero(int hp, int a, int c, int s, std::string& t, int d, int cd, float hPosX, float hPosY):
GameCharacter(hp, a, c, s, t), dashCount(d), cooldown(cd), heroPosX(hPosX), heroPosY(hPosY){

}

Hero::~Hero(){

}

float Hero::getHeroPosX(){
    return heroPosX;
}
void Hero::setHeroPosX(float heroPosX){
    this -> heroPosX = posX;
}

float Hero::getHeroPosY(){
    return heroPosY;
}

void Hero::setHeroPosY(float heroPosY) {
    this -> heroPosY = posY;
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
    GameCharacter::setHp(GameCharacter::getHp+amount);
}

void Hero::addItem() {

}

void Hero::useItem() {

}

void Hero::switchZone() {

}

void Hero::useBonfire() {

}

/**
 * @param bool isKnight
 */
void Hero::raiseShield(void bool isKnight) {

}

/**
 * @param bool isMage
 * @param int cooldown
 * @return override
 */
override Hero::attack(void bool isMage, void int cooldown) {
    return null;
}

/**
 * @return override
 */
override Hero::movement() {
    return null;
}


void Hero::respawn(float posX,float posY) {
    //finish hero
}