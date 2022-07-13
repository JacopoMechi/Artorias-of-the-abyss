#include "gtest/gtest.h"
#include "../src/GameCharacters/Hero.h"
#include "../src/GameCharacters/Enemies/Enemy1.h"
#include "../src/Game.h"
#include <SFML/Graphics.hpp>

TEST(Hero, TestAttack){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "testing attack");
    Hero h(window, true, {500, 500},1 , 100, 0, 100);
    Enemy1 e(window, {730, 266}, 1, 100, 0, 100);
    Game game(window);
}

/*class EntitiesSuite : public ::testing::Test{
  protected:
    virtual void setUp(){
        //e.setPosition({});
    }
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "attack test");  
    Hero h(window, true, {500, 500}, 1, 100, 0, 100);
    Enemy1 e(window, {730, 266}, 1, 100, 0, 100);
    Game game(window);
};

TEST_F(EntitiesSuite, TestAttack){
    h.attack(window);
    h.dealDamage(e);
    ASSERT_EQ(5, h.getWeapon() -> getDamage());//checking if it deals the correct amount of damage
    ASSERT_EQ(-4, e.getHp());//checking if he received damage
}*/