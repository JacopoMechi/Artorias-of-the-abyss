#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int a, int c, int mS): HP(hp), armor(a), cash(c), movementSpeed(mS),
weapon(nullptr), leftWeapon(nullptr){
}
GameCharacter::GameCharacter(const sf::Vector2f& pos, sf::Texture texture, float rectPosX, float rectPosY, float rectWidth, 
        float rectHeight):  pos(pos), texture(texture),  rectPosX(rectPosX), rectPosY(rectPosY), rectWidth(rectWidth), 
        rectHeight(rectHeight){
    for (int i = 0; i < nFrames; i++){
        frames[i] = {rectPosX+i*rectWidth, rectPosY, rectWidth, rectHeight};
    }
    sprite.setTextureRect({rectPosX, rectPosY, rectWidth, rectHeight});//TODO FINISH
    animations[int(AnimationIndex::WalkingUp)] = Animation();//TODO needs to be adjusted
    animations[int(AnimationIndex::WalkingDown)] = Animation();
    animations[int(AnimationIndex::WalkingLeft)] = Animation();
    animations[int(AnimationIndex::WalkingRight)] = Animation();
    animations[int(AnimationIndex::Idle)] = Animation();
}

void GameCharacter::draw(sf::RenderTarget& rt) const{
    rt.draw(sprite);
}

void GameCharacter::setDirection(const sf::Vector2f& dir){
    vel = dir*speed;
    if(dir.x > 0.0f){
        curAnimation = AnimationIndex::WalkingRight;
    }else if(dir.x < 0.0f){
        curAnimation = AnimationIndex::WalkingLeft;
    }else if(dir.y < 0.0f){
        curAnimation = AnimationIndex::WalkingUp;
    }else if(dir.y > 0.0f){
        curAnimation = AnimationIndex::WalkingDown;
    }else
        curAnimation = AnimationIndex::Idle;

}

void GameCharacter::update(float dt){
    pos += vel*dt;
    animations[int(curAnimation)].update(dt);
    animations[int(curAnimation)].applyToSprite(sprite);
    sprite.setScale(0.3f, 0.3f);
    sprite.setPosition(pos);
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


void GameCharacter::movement() {
    //will be overrided in Hero and Enemy
}

void GameCharacter::attack(GameCharacter &opponent) {//its virtual, needs to be overrided in enemy
    //TODO with SFML library type if (sf::Keyboard::isPressed(sf::Keyboard::E){}
    int hit = 1;
    if(weapon){//and something else
        hit = weapon -> getDamage();//edited in weapon -> from void use to int use
    }
    opponent.receiveDamage(hit);
}

/*bool GameCharacter::isChasing(int aggroDistance, const GameCharacter &enemy) {//TODO needs to be edited
    if (sf::norm(pos-enemy.pos) > aggroDistance) //is it ok?
        return false;
    return true;
}*/