#include "Inventory.h"

Inventory::Inventory(bool isOpen): isOpen(isOpen){
    sf::Sprite inventorySprite(inventoryTexture);
    inventoryTexture.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/PlayerHUD.png");
}

bool Inventory::getIsOpen(){
    return isOpen;
}

void Inventory::setIsOpen(bool isOpen){
    this -> isOpen = isOpen;
}

void Inventory::use() {
    //TODO with SFML, key press check, and open a graphic interface
    //TODO in main, create items' objects in a array and, then use them here
    //itemList[itemTracker]... TODO display in the graphic interface
    inventorySprite.setTexture(inventoryTexture);
    inventorySprite.setTextureRect({71, 10, 356, 500});//414
    inventorySprite.setPosition(71,10);
    inventorySprite.setScale(0.9f, 0.9f);
    this -> setIsOpen(true);
}

void Inventory::draw(sf::RenderTarget& rt) const{
    rt.draw(inventorySprite);
}