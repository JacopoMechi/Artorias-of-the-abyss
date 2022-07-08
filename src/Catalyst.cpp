#include "Catalyst.h"

void Catalyst::setLevel(int level) //TODO Choose damage for every level
{
    this->level = level;
    if (level == 1)
        damage = 5;
    else if (level == 2)
        damage = 10;
    else if (level == 3)
        damage = 15;
}

void Catalyst::use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt){
    if(startAnimation){
        window.draw(spellSprite);
        //setting position and rectangles of the weapon
        if(entityRect.width > 0){
            currentRect = weaponRect;
            xVariation = 10;
            yVariation = 40;
        }else if(entityRect.width < 0){
            currentRect = {weaponRect.width, weaponRect.top, -weaponRect.width, weaponRect.height};
            xVariation = -20;
            yVariation = 40;
        }

        //updating iFrames for weapon
        weaponAnimationTime += dt;
        if(weaponAnimationTime >= weaponAnimationHolding){
            iWeaponFrame = (++iWeaponFrame) % nFrames;
            weaponAnimationTime = 0.0f;
            if(iWeaponFrame == 0){
                startAnimation = false;
                startSpell = true;
            }
        }

        //drawing animation
        if(startAnimation){
            weaponSprite.setPosition(entityPos.x+xVariation, entityPos.y+yVariation);
            weaponSprite.setTextureRect({currentRect.left + iWeaponFrame*abs(currentRect.width), currentRect.top, currentRect.width, currentRect.height});
            window.draw(weaponSprite);
        }
    }

    if(startSpell){
        if(0 < spellPos.x && spellPos.x < 1920){ //to set the range of the spell       

            //to move the spell horizzontaly
            spellPos.x += spellSpeed*dt*spellDirection; 
            spellSprite.setPosition(spellPos);
            
            //printing on screen
            window.draw(spellSprite);
        }else
            startSpell = false;
    }
}

void Catalyst::setSpellDirection(sf::Vector2f heroPos, sf::IntRect heroRect){
    if(heroRect.width > 0){
        spellDirection = 1; //right
        spellPos.x = heroPos.x + 150;
        currentSpellRect = spellRect;
    }if(heroRect.width < 0){
        spellDirection = -1; //left
        spellPos.x = heroPos.x - 150;
        currentSpellRect = {spellRect.width, spellRect.top, -spellRect.width, spellRect.height};
    }
    spellPos.y = heroPos.y +40;
    spellSprite.setTextureRect(currentSpellRect);
    spellSprite.setPosition(spellPos);
}

bool Catalyst::getStartSpell() const{
    return startSpell;
}

Catalyst::Catalyst(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level) : 
    Weapon(weaponRect, weaponScale, nFrames, level) {
    spellSprite.setTexture(texture);
    spellRect = {3,299, 33, 20};
    currentSpellRect = spellRect;
    spellSprite.setTextureRect(currentSpellRect);
    spellSprite.setScale(3.5f, 3.5f);
    spellPos = {650, 540};//the hero spawn facing to the right and at the position 500, 500
    spellSprite.setPosition(spellPos);
}