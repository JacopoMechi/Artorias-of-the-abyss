#include "NPC.h"

NPC::NPC(sf::RenderWindow &window, int type, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed) : 
    window(window), type(type), GameCharacter(pos, hp, armor, cash, movementSpeed){
    //loading NPC's texture
    texture.loadFromFile("../Textures/Textures.png");
    sprite.setTexture(texture);
    //setting NPC's scale
    sprite.setScale(5.0f, 5.0f);
    //setting NPC's position
    sprite.setPosition(pos);
    //loading npcs sprites' rectangles
    //chester
    if(type == 0){
        sprite.setTextureRect({394, 22, 16, 14});

        //setting up items for chester
        //homeward bones
        merch[1] -> setItemCount(50);

        //chester's dialogue
        textPool.resize(sizeof(chesterPool)/sizeof(std::string));
        textPool.insert(textPool.begin(), &chesterPool[0], &chesterPool[sizeof(chesterPool)/sizeof(std::string)]);
    //elizabeth
    }else if(type == 1){  
        sprite.setTextureRect({393, 40, 22, 25});

        //setting up items for elizabeth
        //pendant
        merch[2] -> setItemCount(1);
        //green blossom
        merch[0] -> setItemCount(50);
        
        //elizabeth's dialogue
        textPool.resize(sizeof(elizabethPool)/sizeof(std::string));
        textPool.insert(textPool.begin(), &elizabethPool[0], &elizabethPool[(sizeof(elizabethPool)/sizeof(std::string))]);
    //dusk    
    }else if(type == 2){
        sprite.setTextureRect({422, 35, 23, 30});

        //dusk's dialogue
        textPool.resize(sizeof(duskPool)/sizeof(std::string));
        textPool.insert(textPool.begin(), &duskPool[0], &duskPool[sizeof(duskPool)/sizeof(std::string)]);
    //sif
    }else if(type == 3){
        sprite.setTextureRect({452, 38, 25, 27});    
    }else
        std::cout << "Error on loading the NPC" << std::endl;
}

NPC::~NPC(){
    //deleting merch array
    for(int i = 0; i < 3; i++)
        delete merch[i];
}

void NPC::interact(Hero &hero) {
   
}

void NPC::updateInputs(sf::Event keyInput, Hero &hero){
    if(aggro){
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q){
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

    //handling inputs for scrolling through items in shop (for type = 1)//TODO
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Up && type == 1)
        trackerPos = {773, 340};
    else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Down && type == 1)
        trackerPos = {773, 445};   

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

    //handling inputs for buying items
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1 && isBuying){
        if(price <= hero.getMoneyAmount()){
            hero.setMoneyAmount(hero.getMoneyAmount() - price);
            if(type == 0)
                    //interface.setItemAmount(2, 1);
                    merch[1] -> setItemCount((merch[1] -> getItemCount() + 1));
                else if (trackerPos.x == 773 && trackerPos.y == 340) //first item of elizabeth
                    merch[0] -> setItemCount((merch[0] -> getItemCount() + 1));
                    //interface.setItemAmount(1, 1);
                else //second item of elizabeth
                    merch[2] -> setItemCount((merch[2] -> getItemCount() + 1));
                    //interface.setItemAmount(3, 1);

            printErrorMessage = false;
        }else
            printErrorMessage = true;
    }
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2 && isBuying){
        if((5*price) <= hero.getMoneyAmount()){
            hero.setMoneyAmount(hero.getMoneyAmount() - (price*5));
            if(type == 0)
                    merch[1] -> setItemCount((merch[1] -> getItemCount() + 5));
                    //interface.setItemAmount(2, 1);
                else if (trackerPos.x == 773 && trackerPos.y == 340) //first item of elizabeth
                    merch[0] -> setItemCount((merch[0] -> getItemCount() + 5));
                    //interface.setItemAmount(1, 1);
                else //second item of elizabeth
                    merch[2] -> setItemCount((merch[2] -> getItemCount() + 5));
                    //interface.setItemAmount(3, 1);

            printErrorMessage = false;
        }else
            printErrorMessage = true;
    }
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2 && isBuying){
        if((10*price) <= hero.getMoneyAmount()){
            hero.setMoneyAmount(hero.getMoneyAmount() - (price*10));
            if(type == 0)
                    merch[1] -> setItemCount((merch[1] -> getItemCount() + 10));
                    //interface.setItemAmount(2, 1);
                else if (trackerPos.x == 773 && trackerPos.y == 340) //first item of elizabeth
                    merch[0] -> setItemCount((merch[0] -> getItemCount() + 10));
                    //interface.setItemAmount(1, 1);
                else //second item of elizabeth
                    merch[2] -> setItemCount((merch[2] -> getItemCount() + 10));
                    //interface.setItemAmount(3, 1);

            printErrorMessage = false;
        }else
            printErrorMessage = true;
    }
}

void NPC::drawText(std::wstring text, sf::Vector2f textPos){
    interactText.setPosition(textPos);
    interactText.setString(text);
    window.draw(interactText);
}

void NPC::drawInteractBox(sf::Vector2f pos){
    interactionBoxSprite.setPosition(pos);
    window.draw(interactionBoxSprite);
}

void NPC::drawShop(Item* item1){
    item1 -> displayItem(780, 355, window);
    item1 -> displayName(window, 900, 360);
}

void NPC::drawShop(Item* item1, Item* item2){
    item1 -> displayItem(785, 358, window);
    item1 -> displayName(window, 900, 360);
    item2 -> displayItem(780, 463, window);
    item2 -> displayName(window, 900, 470);
}

void NPC::drawTracker(sf::Vector2f pos){
    trackerSprite.setPosition(pos);
    window.draw(trackerSprite);
}

bool NPC::getIsInteraction(){
    return isInteraction;
}

//set aggro for HUD class
void NPC::setAggro(bool aggro){
    this -> aggro = aggro;
}
bool NPC::getAggro(){
    return aggro;
}