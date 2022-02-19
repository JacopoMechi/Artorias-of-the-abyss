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
        shopSprite.setPosition(805, 303);

        //interaction box sprite
        interactionBoxSprite.setTexture(hudTexture);
        interactionBoxSprite.setTextureRect({993, 317, 289, 96});
        interactionBoxSprite.setPosition({815, 862});

        //text for ineteracting box
        interactFont.loadFromFile("../orangekid.ttf");
        interactText.setFont(interactFont);
        
}

NPC::~NPC(){

}

void NPC::sellItems(Hero &hero) {
    //checking if player is close enough to npc and
    //if true, it will pop-up a box like "Press to interact"
    //and it will be possible to press the interaction button
    if(this -> isAggro(190, hero)){
        if(!openShop){
           window.draw(interactionBoxSprite);//for the interaction box trigger
           this -> drawText("Premi Q per interagire", {855, 889});//for displaying message
        }
        aggro = true;   
    }else
        aggro = false;

    //handling npc shop  
    if(openShop){
        //displaying shop
        window.draw(shopSprite);

        //setting up shop for 
        //chester
        if(type == 0){

        //eliszabeth
        }else if (type == 1){

        }
    }
}

void NPC::updateInputs(sf::Event keyInput){
    if(aggro){
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q)
        openShop = !openShop;//open/close shop
    }
}

void NPC::drawText(std::string text, sf::Vector2f textPos){
    interactText.setPosition(textPos);
    interactText.setString(text);
    window.draw(interactText);
}