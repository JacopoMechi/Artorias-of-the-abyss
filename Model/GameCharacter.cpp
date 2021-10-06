#include "GameCharacter.h"



void GameCharacter::getHp() const{
    return HP;
}

void GameCharacter::setHp(int hp) {
    this->HP = hp;
}

void GameCharacter::getArmor() const{
    return armor;
}

void GameCharacter::setArmor(int armor) {
    this->armor = armor;
}

void GameCharacter::getCash() {
    return cash;
}

void GameCharacter::setCash(void int cash) {
    this->cash = cash;
}

void GameCharacter::getDash() {
    return dashCount;
}

void GameCharacter::setDash(int dashCount) {
    this->dashCount = dashCount;
}

void GameCharacter::getMovementSpeed() const{
    return speed;
}

void GameCharacter::setMovementSpeed(int speed) {
    this->speed = speed;
}

Weapon* GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::receiveDamage() {

}

void GameCharacter::getShield() {
    return leftWeapon;
}

void GameCharacter::setShield(Weapon* leftWeapon) {
    this->leftWeapon = leftWeapon;
}

void GameCharacter::isUnkillable() {

}

void GameCharacter::isDialogue() {

}

void GameCharacter::movement() {
    //will be overrided in Hero and Enemy
}

void GameCharacter::attack() {

}

void GameCharacter::isChasing() {

}

void GameCharacter::respawn() {

}