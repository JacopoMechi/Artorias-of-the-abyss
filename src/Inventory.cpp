#include "Inventory.h"

Inventory::Inventory(sf::RenderWindow &window): window(window){
    if(!texture.loadFromFile("../Textures/PlayerHUD.png"))
        std::cout << "Error on loading textures for inventory" << std::endl;

    //setting inventory sprite
    sprite.setTexture(texture);
    sprite.setTextureRect({89, 259, 352, 450});
    sprite.setPosition(89, 259);
    sprite.setScale(1.5f, 1.5f);

    //setting box sprite for items' descriptions
    descriptionSprite.setTexture(texture);
    descriptionSprite.setTextureRect({528, 293, 430, 233});
    descriptionSprite.setPosition({700, 315});
    descriptionSprite.setScale(1.3f, 1.3f);

    //setting tracker sprite for scrolling through items
    trackerSprite.setTexture(texture);
    trackerSprite.setTextureRect({116, 736, 266, 56});
    trackerSprite.setScale(1.5f, 1.5f);

    //setting assign box sprite
    boxSprite.setTexture(texture);
    boxSprite.setTextureRect({994, 318, 289, 98});
    boxSprite.setPosition({994, 418});

    //setting text for inventory
    if(!font.loadFromFile("../pixelFont.ttf"))
        std::cout << "Error on loading text font for inventory" << std::endl;

    text.setFont(font);
    text.setCharacterSize(20);

}

bool Inventory::getOpen() const{
    return isOpen;
}

void Inventory::setOpen(bool isOpen){
    this -> isOpen = isOpen;
}

Item* Inventory::receiveItem() const{
    return items[tracker];
}

Item* Inventory::receiveItem(int nItem) const{
    return items[nItem];
}

void Inventory::setItemAmount(int nItem, int amount){
    items[nItem] -> setItemCount(items[nItem] -> getItemCount() + amount);
}

int Inventory::getNTab() const{
    return nTab;
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
    isAssign = false;
}

bool Inventory::getShowDescription() const{
    return showDescription;
}

void Inventory::setShowDescription(bool showDescription){
    this -> showDescription = showDescription;
}

void Inventory::displayBox(){
    if(showDescription && isAssign && nTab == 0){//only displays on first tab
        window.draw(boxSprite);
        drawText(L"In quale slot vuoi assegnare \nil seguente oggetto?\n\n                          [1]  [2]  [3]", {1008, 438}, 13);
    }else if(nTab != 0)//to reset assign when changing tab
        isAssign = false;
}

bool Inventory::getAssign() const{
    return isAssign;
}

void Inventory::setAssign(bool isAssign){
    this -> isAssign = isAssign;
}

void Inventory::drawText(std::wstring text, sf::Vector2f pos, int characterSize){
    this -> text.setCharacterSize(characterSize);
    this -> text.setString(text);
    this -> text.setPosition(pos);
    window.draw(this -> text);
}

void Inventory::draw(){
    if(isOpen){
        window.draw(sprite);

        //drawing the name of the tab
        drawText(tabName[nTab], {245, 330}, 20);

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

        //calling function to display assign item
        displayBox();
    }
}

void Inventory::drawDescription(int nItem){
    if(showDescription){
        window.draw(descriptionSprite);
        //drawing sprite inside the the description sprite
        items[nItem] -> displayItem(800, 460, window);
        //drawing description of the item
        drawText(items[nItem] -> getItemDescription(), {950, 415}, 13);
    }else
        isAssign = false;//to remove assign box when description is not displaying
}