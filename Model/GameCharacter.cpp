#include "GameCharacter.h"

GameCharacter::GameCharacter(const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : pos(pos), HP(hp), armor(armor), cash(cash),
                                                                                                          movementSpeed(movementSpeed), weapon(nullptr)
{
}

/*GameCharacter::~GameCharacter() {//TODO
    if (weapon != nullptr)
        delete weapon;
}*/

int GameCharacter::getHp() const
{
    return HP;
}

void GameCharacter::setHp(int hp)
{
    if (hp < 0)
        hp = 0;
    this->HP = hp;
}

sf::Vector2f GameCharacter::getPos() const
{
    return pos;
}

void GameCharacter::setPos(sf::Vector2f pos)
{
    this->pos = pos;
}

int GameCharacter::getArmor() const
{
    return armor;
}

void GameCharacter::setArmor(int armor)
{
    this->armor = armor;
}

int GameCharacter::getCash() const
{
    return cash;
}

void GameCharacter::setCash(int cash)
{
    this->cash = cash;
}

int GameCharacter::getMovementSpeed() const
{
    return movementSpeed;
}

void GameCharacter::setMovementSpeed(int movementSpeed)
{
    this->movementSpeed = movementSpeed;
}

Weapon *GameCharacter::getWeapon()
{
    return weapon;
}

void GameCharacter::setWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}

void GameCharacter::receiveDamage(int points)
{
    points = points * armor / 100;
    setHp(HP - points);
}

void GameCharacter::movement(bool isInventoryOpen, bool isInteracting){
    
}

void GameCharacter::attack(sf::RenderWindow &window){
}

bool GameCharacter::isAggro(float aggroDistance, GameCharacter &entity)
{
    if (abs(sqrt(((entity.getPos().x - pos.x) * (entity.getPos().x - pos.x)) + ((entity.getPos().y - pos.y) * (entity.getPos().y - pos.y)))) < aggroDistance)
        return true;
    else
        return false;
}

void GameCharacter::draw(sf::RenderTarget &rt) const
{
    rt.draw(sprite);
}

void GameCharacter::update(float dt)
{
    vel = dir * movementSpeed;
    pos += vel * dt;

    nFrames = 8;
    if (dir.x > 0.0f){
        frameRect = defaultRect;
    }else if (dir.x < 0.0f){
        frameRect = {defaultRect.width, defaultRect.top, -defaultRect.width, defaultRect.height};//flipped sprite
    }else if(dir.y == 0){
        nFrames = 1;
    } 

    //checking when animationTime reaches max gap (animationHolding): this means that is time to change sprite frame rect
    animationTime += dt;
    if (animationTime >= animationHolding){
        iFrame = (++iFrame) % nFrames;
        animationTime = 0.0f;
    }

    sprite.setTextureRect({frameRect.left + iFrame * abs(frameRect.width), frameRect.top, frameRect.width, frameRect.height});
    sprite.setPosition(pos);
}

sf::Vector2f GameCharacter::getSize() const
{
    return {this->sprite.getScale().x * defaultRect.width, this->sprite.getScale().y * defaultRect.height};
}