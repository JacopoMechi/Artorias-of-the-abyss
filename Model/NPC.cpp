#include "NPC.h"

NPC::NPC(sf::RenderWindow &window, int type, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed) : 
    window(window), type(type), GameCharacter(pos, hp, armor, cash, movementSpeed){
        //loading npcs rectangles
        //chester
        if(type == 0)
            sprite.setTextureRect({394, 22, 16, 14});
        //elizabeth
        else if(type == 1)  
            sprite.setTextureRect({393, 40, 22, 25});
        //dusk    
        else if(type == 2)
            sprite.setTextureRect({422, 35, 23, 30});
        //sif
        else if(type == 3)
            sprite.setTextureRect({452, 38, 25, 27});    


        //loading shop sprite
        hudTexture.loadFromFile("../Textures/PlayerHUD.png");
        shopSprite.setTexture(hudTexture);
        shopSprite.setTextureRect({91, 357, 317, 312});
        shopSprite.setPosition(730, 303);
        shopSprite.setScale(1.5f, 1.5f);

        //interaction box sprite
        interactionBoxSprite.setTexture(hudTexture);
        interactionBoxSprite.setTextureRect({993, 317, 289, 96});

        //text for ineteracting box
        interactFont.loadFromFile("../orangekid.ttf");
        interactText.setFont(interactFont);
}

NPC::~NPC(){
    delete merch;
}

void NPC::interact(Hero &hero) {
    //checking if player is close enough to npc and
    //if true, it will pop-up a box like "Press to interact"
    //and it will be possible to press the interaction button
    if(this -> isAggro(190, hero)){
        if(!isInteraction){
           this -> drawInteractBox({815,862});//for the interaction box trigger
           this -> drawText("Premi Q per interagire", {855, 889});//for displaying message
        }
        aggro = true;   
    }else
        aggro = false;

    //handling npc interaction menu 
    if(isInteraction){
        if(!isShop && !isTalking){
            //displaying interaction box
            this -> drawInteractBox({810, 303});

            //diplaying text for interaction box
            this -> drawText("[1] Parla       [2] Acquista\n[Q] Esci",{825, 305});

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                isShop = !isShop;


        //setting up npc shop    
        }else if(isShop){
            //chester which sells homeward bones
            if(type == 0){
                this -> drawShop(merch[1]);
            //eliszabeth which sells green blossoms and the pendant
            }else if (type == 1){
                this -> drawShop(merch[0], merch[2]);
            }
        }
    }
}

void NPC::updateInputs(sf::Event keyInput){
    if(aggro){
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q)
        isInteraction = !isInteraction;//open/close shop
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
    window.draw(shopSprite);
    item1 -> displayItem(780, 355, window);
}

void NPC::drawShop(Item* item1, Item* item2){
    window.draw(shopSprite);
    item1 -> displayItem(785, 358, window);
    item2 -> displayItem(780, 463, window);
}