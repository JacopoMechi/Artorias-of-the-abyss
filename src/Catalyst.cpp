#include "Catalyst.h"

void Catalyst::setLevel(int level)
{
    /*spellStage.push_back({2, 332, 38, 36});
    spellStage.push_back({3, 299, 33, 20});*/
    this->level = level;
    if (level == 1)
        damage = 15;
    else if (level == 2){
        spellStage.clear();
        spellStage.push_back({46, 332, 38, 36});
        spellStage.push_back({46, 299, 33, 20});
        weaponRect = spellStage[0];
        damage = 20;
    }else if (level == 3){
        spellStage.clear();
        spellStage.push_back({90, 332, 38, 36});
        spellStage.push_back({90, 299, 33, 20});
        weaponRect = spellStage[0];
        damage = 25;
    }
}

void Catalyst::use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt){
    if(startAnimation){
        //window.draw(spellSprite);
        //setting position and rectangles of the weapon
        if(entityRect.width > 0){
            currentRect = weaponRect;
            xVariation = 10;
            yVariation = 40;
        }else if(entityRect.width < 0){
            currentRect = {weaponRect.left + weaponRect.width, weaponRect.top, -weaponRect.width, weaponRect.height};
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
                weaponSprite.setTextureRect(spellStage[1]);
                weaponSprite.setTextureRect(currentSpellRect);
                weaponSprite.setPosition(spellPos);
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
            weaponSprite.setPosition(spellPos);
            
            //printing on screen
            window.draw(weaponSprite);
        }else{
            startSpell = false;
        }
    }
}

void Catalyst::setSpellDirection(sf::Vector2f heroPos, sf::IntRect heroRect){
    if(heroRect.width > 0){
        spellDirection = 1; //right
        spellPos.x = heroPos.x + 150;
        currentSpellRect = spellStage[1];
    }if(heroRect.width < 0){
        spellDirection = -1; //left
        spellPos.x = heroPos.x - 150;
        currentSpellRect = {spellStage[1].left + spellStage[1].width, spellStage[1].top, -spellStage[1].width, spellStage[1].height};
    }
    spellPos.y = heroPos.y +40;
}

bool Catalyst::getStartSpell() const{
    return startSpell;
}

Catalyst::Catalyst(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level) : 
    Weapon(weaponRect, weaponScale, nFrames, level) {
    spellStage.push_back({2, 332, 38, 36});
    spellStage.push_back({3, 299, 33, 20});
    currentSpellRect = spellStage[0];
    spellPos = {650, 540};//the hero spawn facing to the right and at the position 500, 500
    weaponSprite.setPosition(spellPos);
    damage = 15;
}