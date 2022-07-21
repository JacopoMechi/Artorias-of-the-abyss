#include "Catalyst.h"

void Catalyst::setLevel(int level)
{
    this->level = level;
    if (level == 1)
        damage = firstCatalystDamage;
    else if (level == 2){
        spellStage.clear();
        spellStage.push_back({secondCatalystX, secondCatalystY, secondCatalystWidth, secondCatalystHeight});
        spellStage.push_back({secondSpellX, secondSpellY, secondSpellWidth, secondSpellHeight});
        weaponRect = spellStage[0];
        damage = secondCatalystDamage;
    }else if (level == 3){
        spellStage.clear();
        spellStage.push_back({thirdCatalystX, thirdCatalystY, thirdCatalystWidth, thirdCatalystHeight});
        spellStage.push_back({thirdSpellX, thirdSpellY, thirdSpellWidth, thirdSpellHeight});
        weaponRect = spellStage[0];
        damage = thirdCatalystDamage;
    }
}

void Catalyst::use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt){
    if(startAnimation){
        //window.draw(spellSprite);
        //setting position and rectangles of the weapon
        if(entityRect.width > 0){
            currentRect = weaponRect;
            xVariation = xRightCatalystVariation;
            yVariation = yRightCatalystVariation;
        }else if(entityRect.width < 0){
            currentRect = {weaponRect.left + weaponRect.width, weaponRect.top, -weaponRect.width, weaponRect.height};
            xVariation = xLeftCatalystVariation;
            yVariation = yLeftCatalystVariation;
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
        if(!stopAnimation && spellLeftLimit < spellPos.x && spellPos.x < spellRightLimit){ //to set the range of the spell       

            //to move the spell horizzontaly
            spellPos.x += spellSpeed*dt*spellDirection; 
            weaponSprite.setPosition(spellPos);
            
            //printing on screen
            window.draw(weaponSprite);
        }else{
            startSpell = false;
            stopAnimation = false;
        }
    }
}

void Catalyst::setSpellDirection(sf::Vector2f heroPos, sf::IntRect heroRect){
    if(heroRect.width > 0){
        spellDirection = 1; //right
        spellPos.x = heroPos.x + xRightSpellVariation;
        currentSpellRect = spellStage[1];
    }if(heroRect.width < 0){
        spellDirection = -1; //left
        spellPos.x = heroPos.x + xLeftSpellVariation;
        currentSpellRect = {spellStage[1].left + spellStage[1].width, spellStage[1].top, -spellStage[1].width, spellStage[1].height};
    }
    spellPos.y = heroPos.y + ySpellVariation;
}

bool Catalyst::getStartSpell() const{
    return startSpell;
}

Catalyst::Catalyst(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level) : 
    Weapon(weaponRect, weaponScale, nFrames, level) {
    spellStage.push_back(weaponRect);
    spellStage.push_back({firstSpellX, firstSpellY, firstSpellWidth, firstSpellHeight});
    currentSpellRect = spellStage[0];
    spellPos = {catalystSpawnPosX, catalystSpawnPosY};//the hero spawn facing to the right and at the position 500, 500
    weaponSprite.setPosition(spellPos);
    damage = firstCatalystDamage;
}