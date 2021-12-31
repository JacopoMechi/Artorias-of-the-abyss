#include "HUD.h"

HUD::HUD(sf::RenderWindow &window): window(window){

    //setting the font for the text      
    font.loadFromFile("../orangekid.ttf");
    text.setFont(font);

    //adding texture for the hud
    hudTexture.loadFromFile("../Textures/PlayerHUD.png");
    //health
    healthSprite.setTexture(hudTexture);
    healthSprite.setTextureRect({1531, 0, 389, 95});
    healthSprite.setPosition(1610, 0);
    healthSprite.setScale(0.8f, 0.8f);
    //quickslot
    quickslotSprite.setTexture(hudTexture);
    quickslotSprite.setTextureRect({810, 960, 300, 77});
    quickslotSprite.setPosition(810, 960);
    quickslotSprite.setScale(0.8f, 0.8f);
    //actions
    actionsSprite.setTexture(hudTexture);
    actionsSprite.setTextureRect({1743, 363, 85, 351});
    actionsSprite.setPosition(1743, 363);
    actionsSprite.setScale(0.8f, 0.8f);
    //items description
    descriptionSprite.setTexture(hudTexture);
    descriptionSprite.setTextureRect({528, 293, 430, 233});
    descriptionSprite.setPosition(650, 296);
    descriptionSprite.setScale(1.3f,1.3f);
    //inventory
    inventorySprite.setTexture(hudTexture);
    inventorySprite.setTextureRect({89, 259, 352, 500});
    inventorySprite.setPosition(89, 259);
    inventorySprite.setScale(1.5f, 1.5f);
}

bool HUD::getInvIsOpen()
{
    return isInvOpen;
}

void HUD::setFirstTab(bool firstTab){
    this -> firstTab = firstTab;
}

void HUD::draw() const{
    window.draw(healthSprite);
    window.draw(quickslotSprite);
    window.draw(actionsSprite);
}

void HUD::displayHealth(GameCharacter &character){ 
    std::string bar = std::string("HP: ") + std::to_string(character.getHp()) + std::string("/100");
    text.setPosition(1700, 15);
    text.setString(bar);
    window.draw(text);
}


void HUD::drawInventory(){
    window.draw(inventorySprite);
    
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
    if (firstTab){

        //first category    
        //list of consumables
        tab = "Consumabili >";//<tab> cambia categoria, <q> esci dall'inventario, <ArrowUp,ArrDown> scorri items
        //first slot
        flask.displayItem(148, 455, window, 235, 460);
        //second slot
        blossom.displayItem(148, 560, window, 235, 565);
        //third slot
        homeward.displayItem(142, 665, window, 235, 670);
        //fourth slot
        pendant.displayItem(142, 780, window, 235, 770);

    }else{    
        //second category
        //scrolling between collectibles
        tab = "< Collezionabili";
        //for scrolling between pages
        /*if(!switching)
            this -> scrollList();*/
        //first slot
        collectibles[0+(4*inventoryScroll)].displayItem(145, 450, window, 235, 460);
        //second slot
        collectibles[1+(4*inventoryScroll)].displayItem(145, 555, window, 235, 565);
        //third slot
        collectibles[2+(4*inventoryScroll)].displayItem(145, 660, window, 235, 670);
        //fourth slot
        collectibles[3+(4*inventoryScroll)].displayItem(145, 775, window, 235, 770); 
        //for detailed items description
        //also handling input with delaytime   
    }
    this -> displayDescription();
    tabText.setString(tab);
    window.draw(tabText);    
}

void HUD::displayDescription(){
    //setting the description
    text.setPosition(890, 375);
    text.setCharacterSize(20);
    if(switching){
        //drawing description sprite
        window.draw(descriptionSprite);

        //drawing item sprite (and name) and description text
        if(firstTab){
            //shows description of first category
            //EstusFlask
            if(descriptionScroll == 0){
                text.setString(flask.getItemDescription());
                flask.displayItem(760, 450, window, 780, 315);
            }
            //GreenBlossom
            if(descriptionScroll == 1){
                text.setString(blossom.getItemDescription());
                blossom.displayItem(760, 450, window, 780, 315);
            }
            //HomewardBone
            if(descriptionScroll == 2){
                text.setString(homeward.getItemDescription());
                homeward.displayItem(760, 450, window, 780, 315);
            }
            //Pendant
            if(descriptionScroll == 3){
                text.setString(pendant.getItemDescription());
                pendant.displayItem(760, 450, window, 780, 315);
            }
        }else{
            //shows description of second category
            collectibles[descriptionScroll].displayItem(760, 450, window, 780, 315);
            text.setString(collectibles[descriptionScroll].getItemDescription());
        }
        window.draw(text);
    }
}

void HUD::updateEvent(sf::Event keyInput){
    //handling inputs
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::E){
        isInvOpen = !isInvOpen;
        if (!isInvOpen)
            switching = false;
        inventoryScroll = 0;    
    }
    if (isInvOpen){
        //opens items descriptions
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter){
            switching = !switching;
            descriptionScroll = 0;
        }

        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Up){
            //scrolling for description(up)
            if(switching){
                if(firstTab)
                    descriptionScroll = (descriptionScroll + 3)%4;
                else    
                    descriptionScroll = (descriptionScroll+7)%8;
            }
            //scrolling for items (up)
            else
                inventoryScroll = (++inventoryScroll)%2;      
        }

        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Down){
            //scrolling for description (down)
            if(switching){
                if(firstTab)
                    descriptionScroll = (++descriptionScroll)%4;
                else    
                    descriptionScroll = (++descriptionScroll)%8;
            }
            //scrolling for items 
            else
                inventoryScroll = (++inventoryScroll)%2;
        }        
    }         
}

/*//TODO complete later
//updating dt in class
void HUD::updateDelayTime(float dt){
    delayTime = dt;
}*/
