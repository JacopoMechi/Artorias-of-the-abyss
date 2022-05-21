#include "HUD.h"

HUD::HUD(sf::RenderWindow &window, Hero& hero): window(window), hero(hero){

    //setting the font and size for the text      
    font.loadFromFile("../pixelFont.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setScale(0.7f, 0.7f);

    //setting font and size of health text
    healthText.setFont(font);
    healthText.setCharacterSize(20);

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
    //tracker for description
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

HUD::~HUD(){
    //deleting quickslot
    for(int i = 0; i < 3; i++)
        delete quickSlot[i];

    //deleting consumables
    for(int i = 0; i < 4; i++)
        delete consumables[i];    
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
    //displaying inventory
    if(isInvOpen)
        this -> drawInventory();
    //obscure and starting sword attack
    if(hero.getCharacterType()){
        if(hero.getStartAnimation())
            hero.attack(window);
        if(!hero.getCanAttack())
            this -> obscureButton({1750, 375});
    }else{
        //obscure and starting spell attack
        if(hero.getStartAnimation())//for showing the mage's staff
            hero.attack(window);
        if(hero.getStartingSpell()){//displaying spell and obscuring attack icon
            this -> obscureButton({1750, 375}); 
            hero.castSpell(window);
        }
    }
    //obscure dash button when dashes uses reaches 0
    if(hero.getDash() == 0)
        this -> obscureButton({1750, 445});
    //handling aura shield active time and obscuring aura shield sprite
    if(!hero.getAuraReady()){    
        hero.blockDamage(window); 
        this -> obscureButton({1750, 508});
    //obscuring aura shield button if is Mage
    }else if(!hero.getCharacterType())
        this -> obscureButton({1750, 508});
    //obscure interact button when you are not close to an NPC
    if(!NPCAggro)
        this -> obscureButton({1750,575});
    //drawing quickslots items
    quickSlot[0] -> displayItem(850, 975, window);
    quickSlot[1] -> displayItem(937, 975, window);
    quickSlot[2] -> displayItem(1020, 975, window);
    //obscuring quickslot items when they are 0
    if(quickSlot[0] -> getItemCount() == 0)
        this -> obscureButton({847, 971});
    if(quickSlot[1] -> getItemCount() == 0)
        this -> obscureButton({932, 971});    
    if(quickSlot[2] -> getItemCount() == 0)
        this -> obscureButton({1015, 970});
}

void HUD::displayHealth(GameCharacter &character){ 
    std::string bar = std::string("HP: ") + std::to_string(character.getHp()) + std::string("/100");
    healthText.setPosition(1700, 40);
    healthText.setString(bar);
    window.draw(healthText);
}


void HUD::drawInventory(){
    window.draw(inventorySprite);
    
    sf::Text tabText;
    tabText.setFont(font);
    tabText.setPosition(245, 330);
    tabText.setCharacterSize(20);
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
        consumables[0] -> displayName(window, 235, 470);
        //second slot
        consumables[1] -> displayItem(148, 560, window);
        consumables[1] -> displayName(window, 235, 577);
        //third slot
        consumables[2] -> displayItem(148, 670, window);
        consumables[2] -> displayName(window, 235, 680);
        //fourth slot
        consumables[3] -> displayItem(142, 780, window);
        consumables[3] -> displayName(window, 235, 785);

    }else{    
        //second category
        //scrolling between collectibles
        tab = "< Collezionabili";
        
        //first slot
        collectibles[0+(4*inventoryScroll)].displayItem(145, 450, window);
        collectibles[0+(4*inventoryScroll)].displayName(window, 235, 470);
        //second slot
        collectibles[1+(4*inventoryScroll)].displayItem(145, 555, window);
        collectibles[1+(4*inventoryScroll)].displayName(window, 235, 575);
        //third slot
        collectibles[2+(4*inventoryScroll)].displayItem(145, 660, window);
        collectibles[2+(4*inventoryScroll)].displayName(window, 235, 680);
        //fourth slot
        collectibles[3+(4*inventoryScroll)].displayItem(145, 775, window); 
        collectibles[3+(4*inventoryScroll)].displayName(window, 235, 785);
        //for detailed items description
    }
    tabText.setString(tab);
    window.draw(tabText);    
}

void HUD::displayDescription(){
    //setting the description
    text.setPosition(890, 395);
    if(switching){
        //drawing description sprite
        window.draw(descriptionSprite);

        //drawing item sprite (and name) and description text
        if(firstTab){
            //shows description of first category
            text.setString(consumables[descriptionScroll] -> getItemDescription());
            consumables[descriptionScroll] -> displayItem(760, 450, window);
            sf::Vector2f position(130, 440+(105*descriptionScroll));
            trackerSprite.setPosition({position});//to highlight the item in the inventory
            window.draw(trackerSprite);
        }else{
            //shows description of second category
            collectibles[descriptionScroll].displayItem(760, 450, window);
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
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::E && !isInteracting){// isInteracting to not open the inventory
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
    //for attacking or casting spells
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::F && (hero.getCanAttack() || !hero.getStartingSpell())){
        hero.setStartAnimation(true);
        if(!hero.getCharacterType()){//when hero is a mage
            hero.setSpellDirection();
            hero.setStartingSpell(true);
        }else//when hero is a knight
            hero.setCanAttack(false);
    }
    //for dashes
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Space)
        hero.dash();
    //for raising a shield aura
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::LShift && hero.getCharacterType())
        hero.setAuraReady(false);

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