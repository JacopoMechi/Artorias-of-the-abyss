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
    descriptionSprite.setPosition({700, 315});
    descriptionSprite.setScale(1.3f, 1.3f);

    //setting tracker sprite for scrolling through items
    trackerSprite.setTexture(texture);
    trackerSprite.setTextureRect({116, 736, 266, 56});
    trackerSprite.setScale(1.5f, 1.5f);

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
    nTab = abs((nTab - 1) % 2);
}

void Inventory::nextItem(){
    if(tracker + 1 == 4){
        nPage = (nPage + 1) % 2;
    }
    tracker = (tracker + 1) % 4;
}

void Inventory::previousItem(){
    if(tracker - 1 == -1){
        nPage = (1 + nPage) % 2;
    }
    tracker = (3 + tracker) % 4;
}

void Inventory::resetPositions(){
    tracker = 0;
    nPage = 0;
    nTab = 0;
    showDescription = false;
}

bool Inventory::getShowDescription() const{
    return showDescription;
}

void Inventory::setShowDescription(bool showDescription){
    this -> showDescription = showDescription;
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

        //displaying tracker for items
        trackerSprite.setPosition(trackerPos[tracker]);
        window.draw(trackerSprite);

        //drawing items of the inventory
        items[0+4*nPage+nTab*8] -> displayItem(148, 455, window);//first slot
        items[0+4*nPage+nTab*8] -> displayName(window, 235, 470);
        items[1+4*nPage+nTab*8] -> displayItem(148, 560, window);//second slot
        items[1+4*nPage+nTab*8] -> displayName(window, 235, 577);
        items[2+4*nPage+nTab*8] -> displayItem(148, 670, window);//third slot
        items[2+4*nPage+nTab*8] -> displayName(window, 235, 680);
        items[3+4*nPage+nTab*8] -> displayItem(142, 780, window);//fourth slot
        items[3+4*nPage+nTab*8] -> displayName(window, 235, 785);

        //calling function to display item's description in case we want the read the item's description
        drawDescription(tracker + nPage*4 + nTab*8);
    }
}

void Inventory::drawDescription(int nItem){
    if(showDescription){
        window.draw(descriptionSprite);
        //setting character size smaller for the moment
        text.setCharacterSize(13);
        //drawing sprite inside the the description sprite
        items[nItem] -> displayItem(800, 460, window);
        //drawing description of the item
        drawText(items[nItem] -> getItemDescription(), {950, 415});
        //reset character size
        text.setCharacterSize(20);
    }
}