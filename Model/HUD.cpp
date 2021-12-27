#include "HUD.h"

HUD::HUD(bool isInvOpen, bool firstTab, int nScroll, sf::RenderWindow &window): 
        isInvOpen(isInvOpen), firstTab(firstTab), nScroll(nScroll), window(window){
    font.loadFromFile("../orangekid.ttf");
    text.setFont(font);

    hudTexture.loadFromFile("../Textures/PlayerHUD.png");
    healthSprite.setTexture(hudTexture);
    quickslotSprite.setTexture(hudTexture);
    actionsSprite.setTexture(hudTexture);
    descriptionSprite.setTexture(hudTexture);
    healthSprite.setTextureRect({1531, 0, 389, 95});
    quickslotSprite.setTextureRect({810, 960, 300, 77});
    actionsSprite.setTextureRect({1743, 363, 85, 351});
    descriptionSprite.setTextureRect({528, 293, 430, 233});
    healthSprite.setPosition(1610, 0);
    quickslotSprite.setPosition(810, 960);
    actionsSprite.setPosition(1743, 363);
    descriptionSprite.setPosition(650, 296);
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

    //manages switch between tabs  
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            this -> setFirstTab(true);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            this -> setFirstTab(false);

    //inventory interface        
    if (this -> firstTab){

        //first category    
        //list of consumables
        tab = "Consumabili >";//<tab> cambia categoria, <q> esci dall'inventario, <ArrowUp,ArrDown> scorri items
        //first slot
        flask.displayItem(148, 455, rt, 235, 460);
        //second slot
        blossom.displayItem(148, 560, rt, 235, 565);
        //third slot
        homeward.displayItem(142, 665, rt, 235, 670);
        //fourth slot
        pendant.displayItem(142, 780, rt, 235, 770);

    }else{    
        //second category
        //scrolling between collectibles
        tab = "< Collezionabili";
        //for scrolling between pages
        this -> scrollList();
        //first slot
        collectibles[1*this -> nScroll].displayItem(145, 450, rt, 235, 460);
        //second slot
        collectibles[2*this -> nScroll].displayItem(145, 555, rt, 235, 565);
        //third slot
        collectibles[3*this -> nScroll].displayItem(145, 660, rt, 235, 670);
        //fourth slot
        collectibles[4*this -> nScroll].displayItem(145, 775, rt, 235, 770); 
        //for detailed items description
        //also handling input with delaytime
        this -> displayDescription();    
        tabText.setString(tab);
        rt.draw(tabText);
    }    
    
}

void HUD::openCloseInv(){//TODO adjust inputs with dt
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        this -> setInvIsOpen(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        this -> setInvIsOpen(false);
    }
}

void HUD::scrollList(){//TODO same here
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this -> nScroll = 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this -> nScroll = 2;    
}

void HUD::displayDescription(){//TODO must be finished and make the code more readable
    if(switching)
        window.draw(descriptionSprite);//example
}

void HUD::updateEvent(sf::Event keyInput){
    //this -> keyInput = keyInput;
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter){
            switching = !switching;
            std::cout << switching << std::endl;
        } 
}

/*//TODO complete later
//updating dt in class
void HUD::updateDelayTime(float dt){
    delayTime = dt;
}*/