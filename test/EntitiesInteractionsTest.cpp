#include "gtest/gtest.h"
#include "../src/GameCharacters/Hero.h"
#include "../src/GameCharacters/Enemies/Enemy1.h"
#include "../src/Game.h"
#include "../src/Item.h"
#include <SFML/Graphics.hpp>

//testing if knight deals damage to enemy
TEST(Hero, TestAttack){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "testing attack");
    Hero h(window, true, {500, 500}, 1 , 100, 0);
    Enemy1 e(window, {730, 266}, 1, 0, 0, 100);
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

//testing if mage deals damage to enemy
TEST(Mage, TestAttack){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "testing attack");
    Hero h(window, false, {500, 500}, 1 , 100, 0);
    Enemy1 e(window, {800, 500}, 1, 0, 0, 100);
    h.getWeapon() -> setStartAnimation(true);
    h.setCanAttack(false);
    h.updateDelay(0.016725f);
    while(e.getHp() >= 0){
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
    ASSERT_EQ(15, h.getWeapon() -> getDamage());//checking if it deals the correct amount of damage
    ASSERT_EQ(-14, e.getHp());//checking if he received damage
}

//testing if enemy deals damage to hero
TEST(Enemy, TestAttack){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "testing attack");
    Hero h(window, true, {500, 500}, 1 , 0, 0);
    Enemy1 e(window, {800, 500}, 1, 0, 0, 100);
    h.getWeapon() -> setStartAnimation(true);
    h.setCanAttack(false);
    h.updateDelay(0.016725f);
    while(!e.getSprite().getGlobalBounds().intersects(h.getSprite().getGlobalBounds())){
        window.clear();
        //for testing the attack we set delayTime of hero to 0.016725 (we suppose to get the time to execute all the functions)  
        h.update(0.016725f);
        e.update(0.016725f); 
        h.draw(window);     
        e.draw(window);
        e.attack(h, 0.016725f);
        window.display();
    }
    ASSERT_EQ(0, h.getHp());//checking if hero received damage
}

//testing if potions heals hero properly
TEST(Hero, heal){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "testing attack");
    Hero h(window, true, {500, 500}, 1 , 100, 0);
    EstusFlask e;
    e.use(h);
    ASSERT_EQ(31, h.getHp());//checking if hero healed successfuly
    ASSERT_EQ(4, e.getItemCount ());//checking if estus flask's counter decreased successfuly
}

//testing if homeward bone teleports hero at the starting point (because character will not interact with a bonfire)
TEST(Hero, homewardBone){
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "testing attack");
    Hero h(window, true, {1000, 1000}, 1 , 100, 0);
    HomewardBone b;
    b.setItemCount (1);
    b.use(h);

    EstusFlask e;
    e.setItemCount(0);
    //code part where the hero can warp
    //different from original for testing purpose
    if (b.getIsRespawn())
    {
        h.setPos(h.getSpawnPoint());
        h.setHp(100);// reset hero's hp
        e.setItemCount(5 - e.getItemCount()); // reset estus flask amount
        b.setIsRespawn(false);
    }
    //checking if hero teleported Correctly
    ASSERT_EQ(500, h.getPos().x);
    ASSERT_EQ(500, h.getPos().y);

    ASSERT_EQ(100, h.getHp());//checking if hero reset his hp successfuly when teleported
    ASSERT_EQ(0, b.getItemCount ());//checking bone item count
    ASSERT_EQ(false, b.getIsRespawn());//check warp switch status of homeward bone
    ASSERT_EQ(5, e.getItemCount ());//checking estus flask item count reset

}