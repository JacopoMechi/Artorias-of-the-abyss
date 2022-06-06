#include "Inventory.h"

Inventory::Inventory(sf::RenderWindow &window): window(window){
    texture.loadFromFile("../Textures/PlayerHUD.png");

    //setting inventory sprite
    inventorySprite.setTexture(texture);
    inventorySprite.setTextureRect({89, 259, 352, 450});
    inventorySprite.setPosition(89, 259);
    inventorySprite.setScale(1.5f, 1.5f);

    //setting box sprite for items' descriptions
    descriptionSprite.setTexture(texture);
    descriptionSprite.setTextureRect({528, 293, 430, 233});
    descriptionSprite.setScale(1.3f, 1.3f);

    //setting text for inventory
    font.loadFromFile("../pixelFont.ttf");
    text.setFont(font);
    text.setCharacterSize(20);

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

void Inventory::drawText(std::wstring text, sf::Vector2f pos){
    this -> text.setString(text);
    this -> text.setPosition(pos);
    window.draw(this -> text);
}

void Inventory::draw(){
    if(isInventoryOpen){
        window.draw(inventorySprite);

        //drawing the name of the tab
        drawText(tabName[nTab], {245, 330});

        //drawing items of the inventory
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

void Inventory::drawDescription(int nItem){
    window.draw(descriptionSprite);
    //drawing sprite inside the the description sprite
    items[nItem] -> displayItem(760, 450, window);
    //drawing description of the item
    drawText(items[nItem] -> getItemDescription(), {890, 395});
}