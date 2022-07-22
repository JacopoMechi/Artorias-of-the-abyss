#ifndef _CATALYST_H
#define _CATALYST_H

#include "Weapon.h"

class Catalyst : public Weapon
{
public:
    virtual void setLevel(int level) override;

    virtual void use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt) override;

    void setSpellDirection(sf::Vector2f heroPos, sf::IntRect heroRect);

    bool getStartSpell() const;

    explicit Catalyst(sf::IntRect weaponRect = {firstCatalystX, firstCatalystY, firstCatalystWidth, firstCatalystHeight}, sf::Vector2f weaponScale = {catalystScale, catalystScale}, int nFrames = maxCatalystFrames, int level = 1);

    virtual ~Catalyst() = default;

protected:
    //rect for catalyst and spell
    std::vector<sf::IntRect> spellStage;
    //for spell casting
    sf::Vector2f spellPos;
    float spellSpeed = 500;
    //to swap spell in the direction that is casted
    sf::IntRect currentSpellRect;
    int spellDirection = 1;//1 because the hero starts from the right
    //to cast the spell
    bool startSpell = false;
};

#endif //_CATALYST_H