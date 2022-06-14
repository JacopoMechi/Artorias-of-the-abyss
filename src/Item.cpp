#include "Item.h"

Item::Item(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount, sf::IntRect spriteRect, sf::IntRect effectRect) : 
    itemName(itemName), itemPrice(itemPrice), itemDescription(itemDescription), maxItemCount(maxItemCount), itemCount(itemCount), 
    coloredSprite(spriteRect){
        texture.loadFromFile("../Textures/Textures.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(coloredSprite);
        sprite.setScale(2.5f, 2.5f);
        shopItemSprite.setTexture(texture);
        shopItemSprite.setTextureRect(coloredSprite);
        shopItemSprite.setScale(2.5f, 2.5f);
        font.loadFromFile("../pixelFont.ttf");
        name.setFont(font);
        shopItemText.setFont(font);
        shopItemText.setString(itemName);
        shopItemText.setCharacterSize(20);
        itemEffectSprite.setTexture(texture);
        itemEffectSprite.setTextureRect(effectRect);
        itemEffectSprite.setScale(7.0f, 7.0f);
}

int Item::getItemCount() const{
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

std::wstring Item::getItemName() const{
    return itemName;
}

std::wstring Item::getItemDescription() const{
    if(itemCount > 0)
        return itemDescription;
    else
        return L"...";    
}

int Item::getItemPrice() const{
    return itemPrice;
}

void Item::use(Hero &hero){
    
}

void Item::displayShopItemIcon(sf::Vector2f pos, sf::RenderTarget &window){
    shopItemSprite.setPosition(pos);
    window.draw(shopItemSprite);
}

void Item::displayShopItemName(sf::Vector2f pos, sf::RenderTarget &window){
    shopItemText.setPosition(pos);
    window.draw(shopItemText);
}

void Item::displayEffect(sf::Vector2f pos, sf::RenderTarget &window){
    if(!startEffect){
        itemEffectSprite.setPosition(pos);
        window.draw(itemEffectSprite);
    }
}

void Item::effectTime(float dt){
    if(!startEffect){
        timeEffect += dt;
        if(timeEffect >= 2.0f){ //0.2 is holdtime
            timeEffect = 0.0f;
            startEffect = true;
        }
    }
}