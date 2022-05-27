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
}

void NPC::interact(Hero &hero) {
   
}

void NPC::updateInputs(sf::Event keyInput, Hero &hero){
   
}

void NPC::drawText(std::wstring text, sf::Vector2f textPos){
    interactText.setPosition(textPos);
    interactText.setString(text);
    window.draw(interactText);
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