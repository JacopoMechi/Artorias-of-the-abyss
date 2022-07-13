#include "gtest/gtest.h"
#include "../src/GameCharacters/Hero.h"
#include "../src/GameCharacters/Enemies/Enemy1.h"
#include "../src/Game.h"
#include <SFML/Graphics.hpp>

TEST(Hero, TestAttack){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "testing attack");
    Hero h(window, true, {500, 500},1 , 100, 0, 100);
    Enemy1 e(window, {730, 266}, 1, 100, 0, 100);
    h.getWeapon() -> setStartAnimation(true);
    h.setCanAttack(false);
    h.updateDelay(0.016725f);
    while(h.getWeapon() -> getIFrame() < h.getWeapon() -> getNFrames()-1){
        window.clear();
        //for testing the attack we set delayTime of hero to 0.016725 (we suppose to get the time to execute all the functions)  
        h.update(0.016725f);
        e.update(0.016725f); 
        h.draw(window);     
        e.draw(window);
        h.attack(window);
        h.dealDamage(e);
        window.display();
    }
    ASSERT_EQ(5, h.getWeapon() -> getDamage());//checking if it deals the correct amount of damage
    ASSERT_EQ(-4, e.getHp());//checking if he received damage
}