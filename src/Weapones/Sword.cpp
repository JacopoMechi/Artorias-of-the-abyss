#include "Sword.h"

void Sword::setLevel(int level)
{
    this->level = level;
    if (level == 1)
        damage = firstSwordDamage;
    else if (level == 2){
        weaponRect = {secondSwordX, secondSwordY, secondSwordWidth, secondSwordHeight};
        damage = secondSwordDamage;
    }else if (level == 3){
        weaponRect = {thirdSwordX, thirdSwordY, thirdSwordWidth, thirdSwordHeight};
        damage = thirdSwordDamage;
    }
}

void Sword::use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt){
    if(startAnimation){
        //setting position and rectangles of the weapon
        if(entityRect.width > 0){
            currentRect = weaponRect;
            xVariation = swordRightPosX;
            yVariation = swordRightPosY;
        }else if(entityRect.width < 0){
            currentRect = {weaponRect.width, weaponRect.top, -weaponRect.width, weaponRect.height};
            xVariation = swordLeftPosX;
            yVariation = swordLeftPosY;
        }

        //updating iFrames for weapon
        weaponAnimationTime += dt;
        if(weaponAnimationTime >= weaponAnimationHolding){
            iWeaponFrame = (++iWeaponFrame) % nFrames;
            weaponAnimationTime = 0.0f;
            if(iWeaponFrame == 0)
                startAnimation = false;
        }

        //drawing animation
        if(startAnimation){
            weaponSprite.setPosition(entityPos.x+xVariation, entityPos.y+yVariation);
            weaponSprite.setTextureRect({currentRect.left + iWeaponFrame*abs(currentRect.width), currentRect.top, currentRect.width, currentRect.height});
            window.draw(weaponSprite);
        }
    }
}

Sword::Sword(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level) : 
    Weapon(weaponRect, weaponScale, nFrames, level) { 
        damage = firstSwordDamage;
    }
