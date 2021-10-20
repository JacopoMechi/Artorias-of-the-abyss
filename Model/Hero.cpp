/**
 * Project Untitled
 */


#include "Hero.h"

/**
 * Hero implementation
 */


/**
 * per drop e shop
 */
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

/**
 * @return override
 */
override Hero::respawn() {
    return null;
}