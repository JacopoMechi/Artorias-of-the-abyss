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

void Inventory::nextTab(){
    nTab = (nTab + 1) % 2;
}

void Inventory::previousTab(){
    nTab = (nTab - 1) % 2;
}

void Inventory::nextPage(){
    nPage = (nPage + 1) % 2;
}

void Inventory::previousPage(){
    nPage = (nPage - 1) % 2;
}

void Inventory::draw() const{
    if(isInventoryOpen){
        window.draw(inventorySprite);
        items[0+4*nPage+nTab*8] -> displayItem(148, 455, window);//first slot
        items[0+4*nPage+nTab*8] -> displayName(window, 235, 470);
        items[1+4*nPage+nTab*8] -> displayItem(148, 560, window);//second slot
        items[1+4*nPage+nTab*8] -> displayName(window, 235, 577);
        items[2+4*nPage+nTab*8] -> displayItem(148, 670, window);//third slot
        items[2+4*nPage+nTab*8] -> displayName(window, 235, 680);
        items[3+4*nPage+nTab*8] -> displayItem(142, 780, window);//fourth slot
        items[3+4*nPage+nTab*8] -> displayName(window, 235, 785);
    }
}