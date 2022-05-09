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
        }
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
        interactFont.loadFromFile("../orangekid.ttf");
        interactText.setFont(interactFont);

        //tracker for buying a specific item
        trackerSprite.setTexture(hudTexture);
        trackerSprite.setTextureRect({118, 738, 264, 55});
        trackerSprite.setScale(1.5f, 1.5f);
        trackerSprite.setColor({255,255, 255, 80});
}

NPC::~NPC(){
    delete *merch;
}

void NPC::interact(Hero &hero) {
    //handling npc interaction menu 
    if(isInteraction){
        if(!isShop && !isTalking){

            //displaying interaction box
            this -> drawInteractBox({805, 295});

            //diplaying text for interaction box
            if(type == 0 || type == 1){//for chester and elizabeth
                this -> drawText("[1] Parla       [2] Acquista\n[Q] Esci",{825, 305});
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                    isShop = !isShop;
            }else //for the other npcs
                this -> drawText("[1] Parla       [Q] Esci",{825, 305});

            //selcting between previous choises
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                isTalking = !isTalking;    

        //setting up npc shop    
        }else if(isShop){
            //reset npc dialouge tracker
            dialogueTracker = 0;

            //drawing shop sprite
            window.draw(shopSprite);
            //chester which sells homeward bones
            if(type == 0){

                //drawing tracker for scrolling items in the shop
                this -> drawTracker(trackerPos);

                this -> drawShop(merch[1]);
            //eliszabeth which sells green blossoms and the pendant
            }else if (type == 1){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    trackerPos = {773, 340};
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    trackerPos = {773, 445};   
                this -> drawTracker(trackerPos);
                this -> drawShop(merch[0], merch[2]);
            }
        //starting dialogue with npc    
        }else if(isTalking){
            //showing npc's dialogue box
            this -> drawInteractBox({800, 303});
            //showing dialouge
            if(type == 3)//only Sif has one line of dialogue
                this -> drawText(sifPool, {815, 313});
            else
                this -> drawText(textPool[dialogueTracker], {815, 313});
        }else{

            //reset npc dialouge tracker
            dialogueTracker = 0;
            
            //reset items highlights for shop
            trackerPos = {773, 340};
        }
    }
}

void NPC::updateInputs(sf::Event keyInput){
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
}

void NPC::drawText(std::string text, sf::Vector2f textPos){
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