#ifndef _HUD_H
#define _HUD_h

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Item.h"

class HUD {
public:

    HUD();

    void draw(sf::RenderTarget& rt) const;

protected:
    sf::Texture hudTexture;
    sf::Sprite healthSprite;
    sf::Sprite quickslotSprite;
    sf::Sprite actionsSprite;

};
#endif