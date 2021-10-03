/**
 * Project Untitled
 */


#include "GameCharacter.h"

/**
 * GameCharacter implementation
 */


void GameCharacter::getHp() {

}

/**
 * @param int hp
 */
void GameCharacter::setHp(void int hp) {

}

void GameCharacter::getArmor() {

}

/**
 * @param int defence
 */
void GameCharacter::setArmor(void int defence) {

}

void GameCharacter::getCash() {

}

/**
 * @param int cash
 */
void GameCharacter::setCash(void int cash) {

}

void GameCharacter::getDash() {

}

/**
 * @param int dashCount
 */
void GameCharacter::setDash(void int dashCount) {

}

void GameCharacter::getMovementSpeed() {

}

/**
 * @param int speed
 */
void GameCharacter::setMovementSpeed(void int speed) {

}

void GameCharacter::getWeapon() {

}

/**
 * @param Weapon* weapon
 */
void GameCharacter::setWeapon(void Weapon* weapon) {

}

void GameCharacter::receiveDamage() {

}

void GameCharacter::getShield() {

}

void GameCharacter::setShield() {

}

void GameCharacter::isUnkillable() {

}

void GameCharacter::isDialogue() {

}

void GameCharacter::movement() {

}

void GameCharacter::attack() {

}

void GameCharacter::isChasing() {

}

void GameCharacter::respawn() {

}
/**
 * Hero implementation
 */


/**
 * per drop e shop
 */
void GameCharacter::Hero::addItem() {

}

void GameCharacter::Hero::useItem() {

}

void GameCharacter::Hero::switchZone() {

}

void GameCharacter::Hero::useBonfire() {

}

/**
 * @param bool isKnight
 */
void GameCharacter::Hero::raiseShield(void bool isKnight) {

}

/**
 * @param bool isMage
 * @param int cooldown
 * @return override
 */
override GameCharacter::Hero::attack(void bool isMage, void int cooldown) {
    return null;
}

/**
 * @return override
 */
override GameCharacter::Hero::movement() {
    return null;
}

/**
 * @return override
 */
override GameCharacter::Hero::respawn() {
    return null;
}
/**
 * Enemy implementation
 */


/**
 * @param float dropChance
 */
void GameCharacter::Enemy::dropItem(void float dropChance) {

}

void GameCharacter::Enemy::getAggro() {

}

/**
 * @param float aggroDistance
 */
void GameCharacter::Enemy::setAggro(void float aggroDistance) {

}

/**
 * @param bool isRanged
 * @param int delay
 * @return override
 */
override GameCharacter::Enemy::attack(void bool isRanged, void int delay) {
    return null;
}

/**
 * @param isRanged
 * @return override
 */
override GameCharacter::Enemy::movement(void isRanged) {
    return null;
}

/**
 * @return override
 */
override GameCharacter::Enemy::respawn() {
    return null;
}
/**
 * NPC implementation
 */


void GameCharacter::NPC::sellItems() {

}
/**
 * CharacterFactory implementation
 */


/**
 * @param characterType type
 */
void GameCharacter::CharacterFactory::createCharacter(void characterType type) {

}
/**
 * ItemFactory implementation
 */


/**
 * @param itemType type
 */
void GameCharacter::ItemFactory::createItem(void itemType type) {

}