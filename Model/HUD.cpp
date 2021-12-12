#include "HUD.h"

HUD::HUD(bool isInvOpen, bool firstTab, int nScroll): isInvOpen(isInvOpen), firstTab(firstTab), nScroll(nScroll){
    font.loadFromFile("../orangekid.ttf");
    text.setFont(font);

    hudTexture.loadFromFile("../Textures/PlayerHUD.png");
    healthSprite.setTexture(hudTexture);
    quickslotSprite.setTexture(hudTexture);
    actionsSprite.setTexture(hudTexture);
    healthSprite.setTextureRect({1531, 0, 389, 95});
    quickslotSprite.setTextureRect({810, 960, 300, 77});
    actionsSprite.setTextureRect({1743, 363, 85, 351});
    healthSprite.setPosition(1610, 0);
    quickslotSprite.setPosition(810, 960);
    actionsSprite.setPosition(1743, 363);
    healthSprite.setScale(0.8f, 0.8f);
    quickslotSprite.setScale(0.8f, 0.8f);
    actionsSprite.setScale(0.8f, 0.8f);

    inventorySprite.setTexture(hudTexture);
    inventorySprite.setTextureRect({89, 259, 352, 500});
    inventorySprite.setPosition(89, 259);
    inventorySprite.setScale(1.5f, 1.5f);
}

bool HUD::getInvIsOpen(){
    return isInvOpen;
}

void HUD::setInvIsOpen(bool isInvOpen){
    this -> isInvOpen = isInvOpen;
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
    text.setPosition(1700, 15);
    text.setString(bar);
    rt.draw(text);
}


void HUD::drawInventory(sf::RenderTarget &rt){
    rt.draw(inventorySprite);
    sf::Text tabText;
    tabText.setFont(font);
    tabText.setPosition(245, 310);
    tabText.setCharacterSize(35);
    std::string tab;  
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            this -> setFirstTab(true);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            this -> setFirstTab(false);
    if (this -> firstTab){
        tab = "Consumabili >";//<tab> cambia categoria, <q> esci dall'inventario, <ArrowUp,ArrDown> scorri items
    }else{
        tab = "< Collezionabili";
        this -> scrollList();
        this -> firstCollRaw[this -> nScroll].displayItem(150, 450, rt, 235, 460);
        this -> secCollRaw[this -> nScroll].displayItem(150, 555, rt, 235, 565);
        this -> thirCollRaw[this -> nScroll].displayItem(150, 660, rt, 235, 670);
        this -> fourCollRaw[this -> nScroll].displayItem(155, 775, rt, 235, 770);   
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

void HUD::scrollList(){//FIXME
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this -> nScroll = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this -> nScroll = 1;    
}