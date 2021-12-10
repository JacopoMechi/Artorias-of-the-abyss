#include "Item.h"

Item::Item(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount, int x, int y, int width, int height) : 
    itemName(itemName), itemPrice(itemPrice), itemDescription(itemDescription), maxItemCount(maxItemCount), itemCount(itemCount), 
    x(x), width(width), height(height){
        texture.loadFromFile("../sprites.png");
        sprite.setTexture(texture);
        sprite.setTextureRect({x, y, width, height});

        font.loadFromFile("../orangekid.ttf");
        name.setFont(font);
        textDescription.setFont(font);
}

Item::~Item(){

}

int Item::getItemCount() {
    return itemCount;
}

void Item::setItemCount(int itemCount){
    this -> itemCount = itemCount;
}

void Item::displayItem(int posX, int posY, sf::RenderTarget &rt, int nameX, int nameY, int descrX, int descrY){
    sprite.setPosition({posX, posY});
    if(this -> getItemCount() > 0){
        //display colored sprite
        name.setPosition(nameX, nameY);
        name.setString(this -> getItemName());
        name.setCharacterSize(20);
        textDescription.setPosition(descrX, descrY);
        textDescription.setString(this -> getItemDescription());
        textDescription.setCharacterSize(20);
        rt.draw(name);
        rt.draw(textDescription);
        rt.draw(sprite);
    }else{
        //display gray sprite
    }
}

std::string Item::getItemName() {
    return itemName;
}

std::string Item::getItemDescription() {
    return itemDescription;
}