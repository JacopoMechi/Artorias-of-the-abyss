#include "Inventory.h"

Inventory::Inventory(sf::RenderWindow &window): window(window){
    texture.loadFromFile("../Textures/PlayerHUD.png");

    //setting inventory sprite
    inventorySprite.setTexture(texture);
    inventorySprite.setTextureRect({89, 259, 352, 450});
    inventorySprite.setPosition(89, 259);
    inventorySprite.setScale(1.5f, 1.5f);
}

bool Inventory::getInvOpen() const{
    return isInventoryOpen;
}

void Inventory::setInvOpen(bool isInventoryOpen){
    this -> isInventoryOpen = isInventoryOpen;
}

int Inventory::getItemCount(Item &item) const{
    return item.getItemCount();
}

void Inventory::setItemCount(Item &item, int value){
    item.setItemCount(value);
}