#include "HUD.h"

HUD::HUD(bool isInvOpen, bool firstTab): isInvOpen(isInvOpen), firstTab(firstTab){
    font.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/orangekid.ttf");
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

    inventorySprite.setTexture(hudTexture);
    inventorySprite.setTextureRect({71, 10, 356, 500});
    inventorySprite.setPosition(71, 10);
    inventorySprite.setScale(0.9f, 0.9f);
}

bool HUD::getInvIsOpen(){
    return isInvOpen;
}

void HUD::setInvIsOpen(bool isInvOpen){
    this -> isInvOpen = isInvOpen;
}

bool HUD::getFirstTab(){
    return firstTab;
}

void HUD::setFirstTab(bool firstTab){
    this -> firstTab = firstTab;
}

void HUD::draw(sf::RenderTarget &rt) const{
    rt.draw(healthSprite);
    rt.draw(quickslotSprite);
    rt.draw(actionsSprite);
}

void HUD::displayHealth(GameCharacter &character, sf::RenderTarget &rt){ 
    std::string bar = std::string("HP: ") + std::to_string(character.getHp()) + std::string("/100");
    text.setPosition(950, 18);
    text.setString(bar);
    rt.draw(text);
}


void HUD::drawInventory(sf::RenderTarget &rt){
    rt.draw(inventorySprite);
    sf::Text tabText;
    tabText.setFont(font);
    tabText.setPosition(160, 120);
    tabText.setCharacterSize(24);
    std::string tab;
    bool first = this -> getFirstTab();  
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            this -> setFirstTab(true);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            this -> setFirstTab(false);
    if (first){
        tab = "Consumabili >";//<tab> cambia categoria, <q> esci dall'inventario, <ArrowUp,ArrDown> scorri items
    }else if(!first){
        tab = "< Collezionabili";    
    }
    tabText.setString(tab);
    rt.draw(tabText);
}

void HUD::openCloseInv(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        this -> setInvIsOpen(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        this -> setInvIsOpen(false);
    }
}