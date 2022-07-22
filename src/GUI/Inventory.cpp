#include "Inventory.h"

Inventory::Inventory(sf::RenderWindow &window): window(window){
    if(!texture.loadFromFile("Textures/PlayerHUD.png"))
        std::cout << "Error on loading textures for inventory" << std::endl;

    //setting inventory sprite
    sprite.setTexture(texture);
    sprite.setTextureRect({invX, invY, invWidth, invHeight});
    sprite.setPosition(invPosX, invPosY);
    sprite.setScale(invScale, invScale);

    //setting box sprite for items' descriptions
    descriptionSprite.setTexture(texture);
    descriptionSprite.setTextureRect({descrX, descrY, descrWidth, descrHeight});
    descriptionSprite.setPosition({descrPosX, descrPosY});
    descriptionSprite.setScale(descrScale, descrScale);

    //setting tracker sprite for scrolling through items
    trackerSprite.setTexture(texture);
    trackerSprite.setTextureRect({trackerX, trackerY, trackerWidth, trackerHeight});
    trackerSprite.setScale(trackerScale, trackerScale);

    //setting assign box sprite
    boxSprite.setTexture(texture);
    boxSprite.setTextureRect({boxX, boxY, boxWidth, boxHeight});
    boxSprite.setPosition({boxPosX, boxPosY});

    //setting text for inventory
    if(!font.loadFromFile("Fonts/pixelFont.ttf"))
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
        drawText(L"In quale slot vuoi assegnare \nil seguente oggetto?\n\n                          [1]  [2]  [3]", {assignTextPosX, assignTextPosY}, 13);
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
        drawText(tabName[nTab], {tabNamePosX, tabNamePosY}, 20);

        //displaying tracker for items
        trackerSprite.setPosition(trackerPos[tracker]);
        window.draw(trackerSprite);

        //drawing items of the inventory
        items[0+4*nPage+nTab*8] -> displayItem(firstItemPosX, firstItemPosY, window);//first slot
        items[0+4*nPage+nTab*8] -> displayName(window, firstItemDescrPosX, firstItemDescrPosY);
        items[1+4*nPage+nTab*8] -> displayItem(secondItemPosX, secondItemPosY, window);//second slot
        items[1+4*nPage+nTab*8] -> displayName(window, secondItemDescrPosX, secondItemDescrPosY);
        items[2+4*nPage+nTab*8] -> displayItem(thirdItemPosX, thirdItemPosY, window);//third slot
        items[2+4*nPage+nTab*8] -> displayName(window, thirdItemDescrPosX, thirdItemDescrPosY);
        items[3+4*nPage+nTab*8] -> displayItem(fourthItemPosX, fourthItemPosY, window);//fourth slot
        items[3+4*nPage+nTab*8] -> displayName(window, fourthItemDescrPosX, fourthItemDescrPosY);

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
        items[nItem] -> displayItem(itemInDescrPosX, itemInDescrPosY, window);
        //drawing description of the item
        drawText(items[nItem] -> getItemDescription(), {itemDescrPosX, itemDescrPosY}, 13);
    }else
        isAssign = false;//to remove assign box when description is not displaying
}