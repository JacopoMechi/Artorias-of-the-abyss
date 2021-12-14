#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int a, int c, float mS, const sf::Vector2f& pos): HP(hp), armor(a), cash(c),
 movementSpeed(mS), pos(pos), weapon(nullptr), leftWeapon(nullptr){
    sprite.setTextureRect({127, 75, 16, 28});//    128, 75, 17, 28
    texture.loadFromFile("../Textures/Textures.png");
    sprite.setTexture(texture);
    sprite.setScale(7.5f, 7.5f);
}

GameCharacter::~GameCharacter() {
    if (weapon != nullptr)
        delete weapon;
    if (leftWeapon != nullptr)
        delete leftWeapon;
}

int GameCharacter::getHp() const{
    return HP;
}

void GameCharacter::setHp(int hp) {
    if (hp < 0)
        hp = 0;
    this->HP = hp;
}

sf::Vector2f GameCharacter::getPos() const{
    return pos;
}

void GameCharacter::setPos(sf::Vector2f pos){
    this -> pos = pos;
}

int GameCharacter::getArmor() const{
    return armor;
}

void GameCharacter::setArmor(int armor) {
    this->armor = armor;
}

int GameCharacter::getCash() const{
    return cash;
}

void GameCharacter::setCash( int cash) {
    this->cash = cash;
}

int GameCharacter::getMovementSpeed() const{
    return movementSpeed;
}

void GameCharacter::setMovementSpeed(int movementSpeed) {
    this->movementSpeed = movementSpeed;
}

Weapon* GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::receiveDamage(int points) {
    points = points*armor/100;
    setHp(HP-points);
}

Weapon* GameCharacter::getShield() {
    return leftWeapon;
}

void GameCharacter::setShield(Weapon* leftWeapon) {
    this->leftWeapon = leftWeapon;
}


void GameCharacter::movement(bool isInventoryOpen){
    if (!isInventoryOpen){

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

void GameCharacter::attack(GameCharacter &opponent) {//its virtual, needs to be overrided in enemy
    //TODO with SFML library type if (sf::Keyboard::isPressed(sf::Keyboard::E){}
    int hit = 1;
    if(weapon){//and something else
        //FIXME hit = weapon->getDamage();//edited in weapon -> from void use to int use
    }
    opponent.receiveDamage(hit);
}

bool GameCharacter::isChasing(float aggroDistance, GameCharacter &enemy) {
    sf::Vector2f enemyPos = enemy.getPos();
    if(sqrt((enemyPos.x - pos.x)*(enemyPos.x - pos.x)+(enemyPos.y - pos.y)*(enemyPos.y - pos.y)) < aggroDistance)
        return true;
    else
        return false;
}

void GameCharacter::draw(sf::RenderTarget &rt) const{
    rt.draw(sprite);
}

void GameCharacter::update(float dt){
    vel = dir*movementSpeed;
    pos += vel*dt;
    
    nFrames = 8;
    if (dir.x > 0.0f){
        frameRect = {0, 0, 16, 22};
    }else if (dir.x < 0.0f){
        frameRect = {16, 0, -16, 22};
    }else if(dir.y == 0){
        nFrames = 1;
    }

    //check when animationTime reaches max gap (animationHolding): this means that is time to change sprite rect
    animationTime += dt;
    if(animationTime >= animationHolding){
        iFrame = (++iFrame)%nFrames;
        animationTime = 0.0f;
    }
    
    sprite.setTextureRect({frameRect.left+iFrame*abs(frameRect.width), frameRect.top, frameRect.width, frameRect.height});
    sprite.setPosition(pos);
}