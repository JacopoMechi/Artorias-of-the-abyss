#include "HUD.h"

HUD::HUD(){
    font.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/yoster.ttf");
    text.setFont(font);
    hudTexture.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/PlayerHUD.png");
    healthSprite.setTexture(hudTexture);
    quickslotSprite.setTexture(hudTexture);
    actionsSprite.setTexture(hudTexture);
    healthSprite.setTextureRect({763, 0, 391, 98});
    quickslotSprite.setTextureRect({447, 570, 302, 78});
    actionsSprite.setTextureRect({1026, 159, 86, 352});
    healthSprite.setPosition(850, 0);
    quickslotSprite.setPosition(450, 570);
    actionsSprite.setPosition(1026, 159);
    healthSprite.setScale(0.8f, 0.8f);
    quickslotSprite.setScale(0.8f, 0.8f);
    actionsSprite.setScale(0.8f, 0.8f);
}

void HUD::draw(sf::RenderTarget& rt) const{
    rt.draw(healthSprite);
    rt.draw(quickslotSprite);
    rt.draw(actionsSprite);
}

void HUD::displayHealth(GameCharacter& character, sf::RenderTarget &rt){ 
    std::string bar = std::string("HP: ") + std::to_string(character.getHp()) + std::string("/100");
    text.setPosition(900, 20);
    text.setString(bar);
    rt.draw(text);
}