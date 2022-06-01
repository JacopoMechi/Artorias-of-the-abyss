#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <SFML/Graphics.hpp>

#include "Hero.h"

class Item
{
public:
    Item(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount, int x, int y, int width, int height); 

    virtual ~Item() = default;

    int getItemCount();

    void setItemCount(int itemCount);

    virtual void displayItem(float posX, float posY, sf::RenderTarget &window);

    void displayName(sf::RenderTarget &window, float nameX, float nameY);

    std::wstring getItemName();

    std::wstring getItemDescription();

    int getItemPrice();

    virtual void use(Hero &hero);

    //displaying item icon for shop
    void displayShopItemIcon(sf::Vector2f pos, sf::RenderTarget &window);

    //displaying item name for shop
    void displayShopItemName(sf::Vector2f pos, sf::RenderTarget &window);

protected:
    sf::Text shopItemText; // to display item name in shop
    sf::Sprite shopItemSprite; //to display the item in shop
    sf::IntRect coloredSprite;
    std::wstring itemName;
    int itemPrice;
    int itemCount;
    std::wstring itemDescription;
    int maxItemCount;
    int x;
    int y;
    float nameX;
    float nameY;
    int width;
    int height;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text name;
};

#endif //_ITEM_H