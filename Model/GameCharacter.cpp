#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int a, int c, int mS, const sf::Vector2f& pos): HP(hp), armor(a), cash(c),
 movementSpeed(mS), pos(pos), weapon(nullptr), leftWeapon(nullptr){
    //need to add a character identifier
    if (curAnimation == AnimationIndex::WalkingRight)
        this -> animation(127, 75, 16, 26, false);//best rect area
    else if (curAnimation == AnimationIndex::WalkingLeft)
        this -> animation(126, 75, 17, 24, true);    
}
void GameCharacter::animation( int x, int y, int width, int height, bool isLeft){
        texture.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/0x72_DungeonTilesetII_v1.4.png");
        if(isLeft){
            for (int i = 0; i < nFrames; i++){
                frames[i] = {x+i*width, y, -width, height};
            }
        }else {
            for (int i = 0; i < nFrames; i++){
                frames[i] = {x+i*width, y, width, height};
            }
        }
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

void GameCharacter::adjourn(float dt){
    time += dt;
    while (time >= holdTime){
        time -=holdTime;
        advance();
    }
}


void GameCharacter::update(float dt){
    pos += vel*dt;
    this -> adjourn(dt);
    this -> applyToSprite(sprite);
    sprite.setScale(2.0f, 2.0f);
    sprite.setPosition(pos);
}

void GameCharacter::applyToSprite(sf::Sprite& s) const {
    s.setTexture(texture);
    s.setTextureRect(frames[iFrame]);
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
        //FIXME hit = weapon->getDamage();//edited in weapon -> from void use to int use
    }
    opponent.receiveDamage(hit);
}

/*bool GameCharacter::isChasing(int aggroDistance, const GameCharacter &enemy) {//TODO needs to be edited
    if (sf::norm(pos-enemy.pos) > aggroDistance) //is it ok?
        return false;
    return true;
}*/