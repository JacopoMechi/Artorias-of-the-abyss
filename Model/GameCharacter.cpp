#include "GameCharacter.h"

GameCharacter::GameCharacter(const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed): pos(pos), HP(hp), armor(armor), cash(cash),
 movementSpeed(movementSpeed), weapon(nullptr){
    
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

void GameCharacter::attack()
{
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
    if (actionStarting)
    {
        nFrames = 4;
        animationHolding = 0.15f;
    }else if (dir.x > 0.0f){
        frameRect = defaultRect;
        lastFrameRect = frameRect;// to set the right position of the caracter when the action animation is over
    }else if (dir.x < 0.0f){
        frameRect = {defaultRect.width, defaultRect.top, -defaultRect.width, defaultRect.height};//flipped sprite

        lastFrameRect = frameRect;//flipped sprite
        
    }else if(dir.y == 0){
        nFrames = 1;
    }

    // check when animationTime reaches max gap (animationHolding): this means that is time to change sprite rect
    animationTime += dt;
    if (animationTime >= animationHolding)
    {
        iFrame = (++iFrame) % nFrames;
        animationTime = 0.0f;
        if (iFrame == nFrames - 1)
        {
            if (actionStarting)
            {
                actionStarting = false;
                frameRect = lastFrameRect;
                iFrame = 1;
            }
            animationHolding = 0.08f;
        }
    }

    sprite.setTextureRect({frameRect.left + iFrame * abs(frameRect.width), frameRect.top, frameRect.width, frameRect.height});
    sprite.setPosition(pos);
}