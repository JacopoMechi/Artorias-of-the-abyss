#include "NPC.h"

NPC::NPC(int type, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed) : 
    GameCharacter(pos, hp, armor, cash, movementSpeed){
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

        //loading sprite file
        texture.loadFromFile("../Textures/Textures.png");
        sprite.setTexture(texture);    
}

NPC::~NPC(){

}

void NPC::sellItems() {

}