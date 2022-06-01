#include "Item.h"

Item::Item(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount, int x, int y, int width, int height) : 
    itemName(itemName), itemPrice(itemPrice), itemDescription(itemDescription), maxItemCount(maxItemCount), itemCount(itemCount), 
    x(x), width(width), height(height){
        texture.loadFromFile("../Textures/Textures.png");
        sprite.setTexture(texture);
        coloredSprite = {x, y, width, height};
        sprite.setTextureRect(coloredSprite);
        sprite.setScale(2.5f, 2.5f);
        shopItemSprite.setTexture(texture);
        shopItemSprite.setTextureRect(coloredSprite);
        shopItemSprite.setScale(2.5f, 2.5f);
        font.loadFromFile("../pixelFont.ttf");
        name.setFont(font);
}

int Item::getItemCount()
{
    return itemCount;
}

void Item::setItemCount(int itemCount)
{
    this->itemCount = itemCount;
}

void Item::displayItem(float posX, float posY, sf::RenderTarget &window){
    sprite.setPosition({posX, posY});
    if(itemCount <= 0)
        //display gray sprite
        sprite.setTextureRect({coloredSprite.left+coloredSprite.width, coloredSprite.top, coloredSprite.width, coloredSprite.height});
    else//setting colored sprite
        sprite.setTextureRect({coloredSprite});    
    window.draw(sprite);
}

void Item::displayName(sf::RenderTarget &window, float nameX, float nameY){
    if(itemCount > 0){
        name.setPosition(nameX, nameY);
        name.setString(itemName);
        name.setCharacterSize(20);
        window.draw(name);
    }
}

std::wstring Item::getItemName()
{
    return itemName;
}

std::wstring Item::getItemDescription() {
    if(itemCount > 0)
        return itemDescription;
    else
        return L"...";    
}

int Item::getItemPrice(){
    return itemPrice;
}

void Item::use(Hero &hero){
    
}

void Item::displayShopIcon(sf::Vector2f pos, sf::RenderTarget &window){
    shopItemSprite.setPosition(pos);
    window.draw(shopItemSprite);
}