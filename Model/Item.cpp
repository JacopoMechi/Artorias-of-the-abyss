#include "Item.h"

Item::Item(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount, int x, int y, int width, int height) : 
    itemName(itemName), itemPrice(itemPrice), itemDescription(itemDescription), maxItemCount(maxItemCount), itemCount(itemCount), 
    x(x), width(width), height(height){
        texture.loadFromFile("../Textures/Textures.png");
        sprite.setTexture(texture);
        sprite.setTextureRect({x, y, width, height});
        this -> x = x;
        this -> y = y;
        this -> width = width;
        this -> height = height;
        sprite.setScale(2.5f, 2.5f);

        font.loadFromFile("../orangekid.ttf");
        name.setFont(font);
}

Item::~Item()
{
}

int Item::getItemCount()
{
    return itemCount;
}

void Item::setItemCount(int itemCount)
{
    this->itemCount = itemCount;
}

void Item::displayItem(float posX, float posY, sf::RenderTarget &window, float nameX, float nameY){
    sprite.setPosition({posX, posY});
    if(this -> getItemCount() > 0){
        //display colored sprite
        name.setPosition(nameX, nameY);
        name.setString(this -> getItemName());
        name.setCharacterSize(30);
        window.draw(name);
    }else{
        //display gray sprite
        sprite.setTextureRect({x+width, y, width, height});
    }
    window.draw(sprite);
}

std::string Item::getItemName()
{
    return itemName;
}

std::string Item::getItemDescription() {
    if(this -> getItemCount() > 0)
        return itemDescription;
    else
        return "...";    
}