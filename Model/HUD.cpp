#include "HUD.h"

HUD::HUD(sf::RenderWindow &window, Hero& hero): window(window), hero(hero){

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
    quickslotSprite.setScale(1.0f, 1.0f);
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
    inventorySprite.setTextureRect({89, 259, 352, 450});
    inventorySprite.setPosition(89, 259);
    inventorySprite.setScale(1.5f, 1.5f);
    //assign popup
    assignSprite.setTexture(hudTexture);
    assignSprite.setTextureRect({994, 318, 289, 98});
    assignSprite.setPosition({994, 318});
    //tracker for description and items in shop //TODO check if shop is here
    trackerSprite.setTexture(hudTexture);
    trackerSprite.setTextureRect({116, 736, 266, 56});
    trackerSprite.setScale(1.5f, 1.5f);

    //setting obscure button sprite
    obscureSprite.setTexture(hudTexture);
    obscureSprite.setTextureRect({1756, 733, 63, 63});
    obscureSprite.setScale(0.9f, 0.9f);

    
    //TODO only for tests. Needs to be removed
    consumables[3] -> setItemCount(1);
    consumables[2] -> setItemCount(1);
    consumables[1] -> setItemCount(1);
}

bool HUD::getInvIsOpen(){
    return isInvOpen;
}

void HUD::setFirstTab(bool firstTab){
    this -> firstTab = firstTab;
}

void HUD::draw() {
    window.draw(healthSprite);
    window.draw(quickslotSprite);
    window.draw(actionsSprite);
    //obscure attack
    if(hero.getStartAnimation())
        hero.attack(window);
    if(!hero.getCanAttack())
        this -> obscureButton({1750, 375});
    //obscure dash button when dashes uses reaches 0
    if(hero.getDash() == 0)
        this -> obscureButton({1750, 445});
    //handling aura shield active time and obscuring aura shield sprite
    if(!hero.getAuraReady()){    
        hero.blockDamage(window); 
        this -> obscureButton({1750, 508});
    }
    //obscure interact button when you are not close to an NPC
    if(!NPCAggro)
        this -> obscureButton({1750,575});
    //drawing quickslots items
    if(quickSlot[0] != NULL)
        quickSlot[0] -> displayItem(850, 975, window);
    if(quickSlot[1] != NULL)
        quickSlot[1] -> displayItem(937, 975, window);
    if(quickSlot[2] != NULL)
        quickSlot[2] -> displayItem(1020, 975, window);
    //obscuring quickslot items when they are 0
    if(quickSlot[0] != NULL && quickSlot[0] -> getItemCount() == 0)
        this -> obscureButton({847, 971});
    if(quickSlot[1] != NULL && quickSlot[1] -> getItemCount() == 0)
        this -> obscureButton({932, 971});    
    if(quickSlot[2] != NULL && quickSlot[2] -> getItemCount() == 0)
        this -> obscureButton({1015, 970});
}

void HUD::displayHealth(GameCharacter &character){ 
    std::string bar = std::string("HP: ") + std::to_string(character.getHp()) + std::string("/100");
    text.setPosition(1700, 15);
    text.setString(bar);
    text.setScale(1.0f,1.0f);
    window.draw(text);
}


void HUD::drawInventory(){
    window.draw(inventorySprite);
    
    sf::Text tabText;
    tabText.setFont(font);
    tabText.setPosition(245, 310);
    tabText.setCharacterSize(35);
    std::string tab;

    //calling description for showing the items in the specific
    this -> displayDescription();

    //manages switch between tabs
    //when true, inventory display consumables' tab
    //when false, inventory display collectibles' tab
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !switching)
            this -> setFirstTab(true);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !switching)
            this -> setFirstTab(false);     

    //inventory interface        
    if (firstTab){

        //first category    
        //list of consumables
        tab = "Consumabili >";//<tab> cambia categoria, <q> esci dall'inventario, <ArrowUp,ArrDown> scorri items
        //first slot
        consumables[0] -> displayItem(148, 455, window);
        consumables[0] -> displayName(window, 235, 460);
        //second slot
        consumables[1] -> displayItem(148, 560, window);
        consumables[1] -> displayName(window, 235, 567);
        //third slot
        consumables[2] -> displayItem(142, 665, window);
        consumables[2] -> displayName(window, 235, 670);
        //fourth slot
        consumables[3] -> displayItem(142, 780, window);
        consumables[3] -> displayName(window, 235, 775);

    }else{    
        //second category
        //scrolling between collectibles
        tab = "< Collezionabili";
        
        //first slot
        collectibles[0+(4*inventoryScroll)].displayItem(145, 450, window);
        collectibles[0+(4*inventoryScroll)].displayName(window, 235, 460);
        //second slot
        collectibles[1+(4*inventoryScroll)].displayItem(145, 555, window);
        collectibles[1+(4*inventoryScroll)].displayName(window, 235, 565);
        //third slot
        collectibles[2+(4*inventoryScroll)].displayItem(145, 660, window);
        collectibles[1+(4*inventoryScroll)].displayName(window, 235, 565);
        //fourth slot
        collectibles[3+(4*inventoryScroll)].displayItem(145, 775, window); 
        collectibles[1+(4*inventoryScroll)].displayName(window, 235, 565);
        //for detailed items description
    }
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
            text.setString(consumables[descriptionScroll] -> getItemDescription());
            consumables[descriptionScroll] -> displayItem(760, 450, window);
            consumables[descriptionScroll] -> displayName(window, 780, 315);
            sf::Vector2f position(130, 440+(105*descriptionScroll));
            trackerSprite.setPosition({position});//to highlight the item in the inventory
            window.draw(trackerSprite);
        }else{
            //shows description of second category
            collectibles[descriptionScroll].displayItem(760, 450, window);
            collectibles[descriptionScroll].displayName(window, 780, 315);
            text.setString(collectibles[descriptionScroll].getItemDescription());
            sf::Vector2f position(130, 440+(105*(descriptionScroll%4)));//for switching category while scrolling through descriptions
            if (descriptionScroll > 3)
                inventoryScroll = 1;
            else
                inventoryScroll = 0;
            trackerSprite.setPosition({position});//to highlight the item in the inventory
            window.draw(trackerSprite);
        }
        window.draw(text);
        drawQuickSlot();
    }
}

void HUD::updateEvent(sf::Event keyInput, bool isInteracting){
    //handling inputs
    //opens inventory
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

        //inputs for scrolling in inventory
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Up&&!quickAssign){//when quickAssign is open, it will not scroll
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

        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Down&&!quickAssign){//when quickAssign is open, it will not scroll
            //scrolling for description (down)
            if(switching){
                if(firstTab)
                    descriptionScroll = (++descriptionScroll)%4;
                else    
                    descriptionScroll = (++descriptionScroll)%8;
            }
            //scrolling for items (down)
            else
                inventoryScroll = (++inventoryScroll)%2;
        }

        //input for changing quickslot items. It opens a dialogue box if description box is opened
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::U && switching&&firstTab){
            quickAssign = !quickAssign;
        }        

        //handling slot assign
        if(quickAssign){
            //std::cout << descriptionScroll << std::endl;
            if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1)
                this -> assignItem(consumables[descriptionScroll], 0);
            else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2)
                this -> assignItem(consumables[descriptionScroll], 1);
            else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3)
                this -> assignItem(consumables[descriptionScroll], 2);
        }
    }else{
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1 && quickSlot[0] != NULL)
            quickSlot[0] -> use(hero);
        else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2 && quickSlot[1] != NULL)
            quickSlot[1] -> use(hero);
        else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3 && quickSlot[2] != NULL)
            quickSlot[2] -> use(hero);
    }

    //hero's dash and attack handling
    //for attacking
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::F && hero.getCanAttack()){
        hero.setStartAnimation(true);
        hero.setCanAttack(false);
    }
    //for dashes
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Space)
        hero.dash();
    //for raising a shield aura
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::LShift)
        hero.setAuraReady(false);
    //hero.blockDamage(window);    

}

//drawing assign popup
void HUD::drawQuickSlot(){
    text.setPosition(1003, 328);
    text.setCharacterSize(20);
    text.setString("In quale slot vuoi assegnare il seguente\n oggetto?\n                          [1]  [2]  [3]");
    if(quickAssign&&firstTab){
        window.draw(assignSprite);
        window.draw(text);
    }
}

void HUD::assignItem(Item *consumable, int slot){
    quickSlot[slot] = consumable;
    quickAssign = false;
}

void HUD::checkNPCAggro(NPC &npc){
    if(npc.isAggro(190, hero)){
        npc.setAggro(true);
        NPCAggro = true;
    }else{
        npc.setAggro(false);
        NPCAggro = false;
    }
}

void HUD::obscureButton(sf::Vector2f pos) {
    obscureSprite.setPosition(pos);
    window.draw(obscureSprite);
}