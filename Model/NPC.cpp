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

        //chester's dialogue
        textPool.resize(sizeof(chesterPool)/sizeof(std::string));
        textPool.insert(textPool.begin(), &chesterPool[0], &chesterPool[sizeof(chesterPool)/sizeof(std::string)]);
    //elizabeth
    }else if(type == 1){  
        sprite.setTextureRect({393, 40, 22, 25});
        
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
}

void NPC::draw(){
    window.draw(sprite);
}

std::vector<std::wstring> NPC::getTextPool(){
    return textPool;
}