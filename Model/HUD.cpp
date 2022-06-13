#include "HUD.h"

HUD::HUD(sf::RenderWindow &window, Hero& hero, Inventory &inventory): window(window), hero(hero), inventory(inventory){

    //setting the font and size for the text      
    font.loadFromFile("../pixelFont.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setScale(0.7f, 0.7f);

    //setting font and size of health text
    healthText.setFont(font);
    healthText.setCharacterSize(20);

    //setting font and size of money counter text
    moneyText.setFont(font);
    moneyText.setCharacterSize(20);

    //setting font and size for counting how many consumables are in a slot in quickslot
    itemAmountText.setFont(font);
    itemAmountText.setCharacterSize(10);

    //adding texture for the hud
    hudTexture.loadFromFile("../Textures/PlayerHUD.png");
    //health
    healthSprite.setTexture(hudTexture);
    healthSprite.setTextureRect({1531, 0, 389, 95});
    healthSprite.setPosition(1610, 0);
    healthSprite.setScale(0.8f, 0.8f);
    //money counter
    moneyCounterSprite.setTexture(hudTexture);
    moneyCounterSprite.setTextureRect({0, 986, 389, 95});
    moneyCounterSprite.setPosition(0,1000);
    moneyCounterSprite.setScale(0.8f, 0.8f);
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
    //setting obscure button sprite
    obscureSprite.setTexture(hudTexture);
    obscureSprite.setTextureRect({1756, 733, 63, 63});
    obscureSprite.setScale(0.9f, 0.9f);

    //loading shop sprite
    hudTexture.loadFromFile("../Textures/PlayerHUD.png");
    shopSprite.setTexture(hudTexture);
    shopSprite.setTextureRect({91, 357, 317, 312});
    shopSprite.setPosition(730, 303);
    shopSprite.setScale(1.5f, 1.5f);

    //interaction box sprite
    interactionBoxSprite.setTexture(hudTexture);
    interactionBoxSprite.setTextureRect({993, 317, 289, 96});
    interactionBoxSprite.setScale(1.7f, 1.7f);

    //setting interaction text
    interactText.setFont(font);
    interactText.setCharacterSize(20);

    //tracker for buying a specific item
    shopTrackerSprite.setTexture(hudTexture);
    shopTrackerSprite.setTextureRect({118, 738, 264, 55});
    shopTrackerSprite.setScale(1.5f, 1.5f);
    shopTrackerSprite.setColor({255,255, 255, 80});

    //drawing error message
    errorMessage.setFont(font);
    errorMessage.setCharacterSize(20);
    errorMessage.setPosition({1250, 380});
    errorMessage.setString(L"Non hai abbastanza monete!");
}

HUD::~HUD(){//FIXME sgmentation fault when closing program. Maybe we don't need this implementation 
    //deleting quickslot
    for(int i = 0; i < 3; i++)
        delete quickSlot[i];

}

void HUD::setTextPool(std::vector<std::wstring> textPool){
    this -> textPool = textPool;
}

void HUD::draw() {
    window.draw(quickslotSprite);
    window.draw(actionsSprite);
    //displaying inventory
    inventory.draw();
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
    //if(!NPCAggro)//TODO here
    //   this -> obscureButton({1750,575});
    //drawing quickslots items
    quickSlot[0] -> displayItem(850, 975, window);
    quickSlot[1] -> displayItem(935, 975, window);
    quickSlot[2] -> displayItem(1020, 975, window);
    //obscuring quickslot items when they are 0
    if(quickSlot[0] -> getItemCount() == 0)
        this -> obscureButton({847, 971});
    if(quickSlot[1] -> getItemCount() == 0)
        this -> obscureButton({932, 971});    
    if(quickSlot[2] -> getItemCount() == 0)
        this -> obscureButton({1015, 970});

    //displaying item counts
    this -> displayItemCount(quickSlot[0], {890, 980});
    this -> displayItemCount(quickSlot[1], {975, 980});
    this -> displayItemCount(quickSlot[2], {1060, 980});

    //drawing npc interaction menu 
    if(isInteraction){
        if(!isShop && !isTalking){

            //displaying interaction box
            this -> drawInteractBox({805, 295});

            //diplaying text for interaction box
            if(NPCType == 0 || NPCType == 1)//for chester and elizabeth
                this -> drawShopText(L"[1] Parla       [2] Acquista\n[Q] Esci",{825, 325});
            else //for the other npcs
                this -> drawShopText(L"[1] Parla       [Q] Esci",{825, 325});

            //resetting values
            //reset npc dialouge tracker
            dialogueTracker = 0;
            
            //reset items highlights for shop
            shopTrackerPos = {768, 336};

            //reset isBuying
            isBuying = false;

            //reset error message
            printErrorMessage = false;

        //setting up npc shop    
        }else if(isShop){
            //reset npc dialouge tracker
            dialogueTracker = 0;

            //drawing shop sprite
            window.draw(shopSprite);
            //chester which sells homeward bones
            if(NPCType == 0){

                //drawing tracker for scrolling items in the shop
                this -> drawShopTracker(shopTrackerPos);

                this -> drawShop(inventory.receiveItem(2));
            //elizabeth which sells green blossoms and the pendant
            }else if (NPCType == 1){
                this -> drawShopTracker(shopTrackerPos);
                this -> drawShop(inventory.receiveItem(1), inventory.receiveItem(3));
            }

            //opening interact menu when trying to buy items
            if(isBuying){
                this -> drawInteractBox({1230,300});
                if(NPCType == 0)
                    price = inventory.receiveItem(2) -> getItemPrice();
                else if (shopTrackerPos.x == 773 && shopTrackerPos.y == 340) //first item of elizabeth
                    price = inventory.receiveItem(1) -> getItemPrice();
                else //second item of elizabeth
                    price = inventory.receiveItem(3) -> getItemPrice();

                this -> drawShopText(L"Quanti ne vuoi acquistare? (" + std::to_wstring(price) + L") \n[1] 1     [2] 5     [3] 10", {1250, 330});

                //displaying error message in case we don't have enough money to buy 
                if(printErrorMessage)
                    window.draw(errorMessage);
            }
        //starting dialogue with npc    
        }else if(isTalking){
            //showing npc's dialogue box
            this -> drawInteractBox({800, 303});
            //showing dialouge
            if(NPCType == 3)//only Sif has one line of dialogue
                this -> drawShopText(L"(Ulula)", {820, 333});
            else
                this -> drawShopText(textPool[dialogueTracker], {820, 333});
        }
    }
}

void HUD::displayHealthAndEffects(Hero &hero){ 
    //drawing effects
    quickSlot[0] -> displayEffect({hero.getPos().x, hero.getPos().y}, window);
    quickSlot[1] -> displayEffect({hero.getPos().x, hero.getPos().y}, window);
    quickSlot[2] -> displayEffect({hero.getPos().x, hero.getPos().y}, window);
    //drawing health
    window.draw(healthSprite);
    std::string bar = std::string("HP: ") + std::to_string(hero.getHp()) + std::string("/100");
    healthText.setPosition(1700, 40);
    healthText.setString(bar);
    window.draw(healthText);
}

/*void HUD::updateEvent(sf::Event keyInput){//, bool isInteracting
    //handling inputs
    //opens inventory
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::E && !isInteraction){// isInteracting to not open the inventory
        inventory.setInvOpen(!inventory.getInvOpen());
        inventory.resetPositions();    
    }
    if (inventory.getInvOpen()){
        //opens items descriptions
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter)
            inventory.setShowDescription(!inventory.getShowDescription());


        //inputs for scrolling in inventory
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Up&&!quickAssign)//when quickAssign is open, it will not scroll
            //scrolling through items (up)
            inventory.previousItem();

        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Down&&!quickAssign)//when quickAssign is open, it will not scroll
            //scrolling through items (down)
            inventory.nextItem();


        //inputs for switching tabs
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Right&&!quickAssign)
            inventory.nextTab();

        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Left&&!quickAssign)
            inventory.previousTab();


        //input for changing quickslot items. It opens a dialogue box
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::U && inventory.getShowDescription()){
            inventory.setAssign(!inventory.getAssign());
        }        

        //handling slot assign
        if(inventory.getNTab() == 0 && inventory.getAssign()){
            //std::cout << descriptionScroll << std::endl;
            if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1){
                quickSlot[0] = inventory.receiveItem();
                inventory.setAssign(false);
            }else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2){
                quickSlot[1] = inventory.receiveItem();
                inventory.setAssign(false);
            }else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3){
                quickSlot[2] = inventory.receiveItem();
                inventory.setAssign(false);
            }
        }
    }else{
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1)
            if(isInteraction && isBuying){//for buying items in shop
                if(price <= hero.getMoneyAmount()){
                    hero.setMoneyAmount(hero.getMoneyAmount() - price);
                    if(NPCType == 0)
                            inventory.setItemAmount(2, inventory.receiveItem(2) -> getItemCount() + 1);
                        else if (shopTrackerPos.x == 773 && shopTrackerPos.y == 340) //first item of elizabeth
                            inventory.setItemAmount(1, inventory.receiveItem(1) -> getItemCount() + 1);
                        else //second item of elizabeth
                            inventory.setItemAmount(3, inventory.receiveItem(3) -> getItemCount() + 1);

                    printErrorMessage = false;
                }else
                    printErrorMessage = true;
            }else{
                quickSlot[0] -> use(hero);
            }
        else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2){
            if(isInteraction && isBuying){//for buying items in shop
                if((5*price) <= hero.getMoneyAmount()){
                    hero.setMoneyAmount(hero.getMoneyAmount() - (price*5));
                    if(NPCType == 0)
                            inventory.setItemAmount(2, inventory.receiveItem(2) -> getItemCount() + 5);
                        else if (shopTrackerPos.x == 773 && shopTrackerPos.y == 340) //first item of elizabeth
                            inventory.setItemAmount(1, inventory.receiveItem(1) -> getItemCount() + 5);
                        else //second item of elizabeth
                            inventory.setItemAmount(3, inventory.receiveItem(3) -> getItemCount() + 5);

                    printErrorMessage = false;
                }else
                    printErrorMessage = true;
            }else{
                quickSlot[1] -> use(hero);
            }
        }else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3){
            if(isInteraction && isBuying){//for buying items in shop
                if((10*price) <= hero.getMoneyAmount()){
                    hero.setMoneyAmount(hero.getMoneyAmount() - (price*10));
                    if(NPCType == 0)
                            inventory.setItemAmount(2, inventory.receiveItem(2) -> getItemCount() + 10);
                        else if (shopTrackerPos.x == 773 && shopTrackerPos.y == 340) //first item of elizabeth
                            inventory.setItemAmount(1, inventory.receiveItem(1) -> getItemCount() + 10);
                        else //second item of elizabeth
                            inventory.setItemAmount(3, inventory.receiveItem(3) -> getItemCount() + 10);

                    printErrorMessage = false;
                }else
                    printErrorMessage = true;
            }else{
                quickSlot[2] -> use(hero);
            }
        }
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

    //handling inputs for interaction with npc
     if(NPCAggro){
        if(!inventory.getInvOpen() && keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q){
            isInteraction = !isInteraction;//open/close shop
            //for resetting interaction
            isShop = false;
            isTalking = false;
        }
    }

    if(isTalking){//TODO LATER adjust dialogue depending on situations (like changing chester's text pool when Artorias is killed)
        //scrolling through character's phrases
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter)
            dialogueTracker = (dialogueTracker+1)%(textPool.size()/2);//FIXME why /2?
    }

    //handling inputs for scrolling through items in shop 
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Up && NPCType == 1)
        shopTrackerPos = {768, 336};
    else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Down && NPCType == 1)
        shopTrackerPos = {768, 441};   

    //opening buying interface
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::U && isShop)
        isBuying = !isBuying;    

    //select talking option in interaction
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1 && isInteraction && !isShop && !isTalking && !isBuying)
        isTalking = !isTalking;    

    //selecting shop option in interaction
    //(only for specifics NPCs)
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2 && !isBuying)
        isShop = !isShop;
}*/

void HUD::assignItemInQuickslot(int slot){
    quickSlot[slot] = inventory.receiveItem();
}

/*void HUD::checkNPCAggro(NPC &npc){
    if(npc.isAggro(190, hero)){
        NPCAggro = true;
    }else{
        NPCAggro = false;
    }
}*/

void HUD::displayMoneyCounter(Hero &hero){
    window.draw(moneyCounterSprite);
    std::string counter = std::string("Monete: ") + std::to_string(hero.getMoneyAmount());
    moneyText.setString(counter);
    moneyText.setPosition(90, 1035);
    window.draw(moneyText);
}

void HUD::obscureButton(sf::Vector2f pos) {
    obscureSprite.setPosition(pos);
    window.draw(obscureSprite);
}

void HUD::displayItemCount(Item* item, sf::Vector2f pos){
    itemAmountText.setString(std::to_wstring(item -> getItemCount()));
    itemAmountText.setPosition(pos);
    window.draw(itemAmountText);
}

void HUD::drawInteractBox(sf::Vector2f pos){
    interactionBoxSprite.setPosition(pos);
    window.draw(interactionBoxSprite);
}

void HUD::setNPCType(int NPCType){
    this -> NPCType = NPCType;
}

void HUD::drawShopTracker(sf::Vector2f pos){
    /*trackerSprite.setPosition(pos);
    window.draw(trackerSprite);*/
}

void HUD::drawShopText(std::wstring text, sf::Vector2f textPos){
    interactText.setPosition(textPos);
    interactText.setString(text);
    window.draw(interactText);
}

void HUD::drawShop(Item* item1){
    item1 -> displayShopItemIcon({780, 355}, window);
    item1 -> displayShopItemName({870, 360}, window);
}

void HUD::drawShop(Item* item1, Item* item2){
    item1 -> displayShopItemIcon({785, 358}, window);
    item1 -> displayShopItemName({870, 360}, window);
    item2 -> displayShopItemIcon({780, 463}, window);
    item2 -> displayShopItemName({870, 470}, window);
}

void HUD::gettingDelayTime(float dt){
    quickSlot[0] -> effectTime(dt);
    quickSlot[1] -> effectTime(dt);
    quickSlot[2] -> effectTime(dt);
}

void HUD::useItem(int nItem, Hero &hero){
    quickSlot[nItem] -> use(hero);
}

//TODO for the moment
bool HUD::getDrawShop(){
    return isShop;
}

void HUD::setDrawShop(bool isShop){
    this -> isShop = isShop;
}

//TODO for the moment
bool HUD::getInteraction(){
    return isInteraction;
}

void HUD::setInteraction(bool isInteraction){
    this -> isInteraction = isInteraction;
}