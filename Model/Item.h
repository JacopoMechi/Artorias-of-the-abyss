#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <SFML/Graphics.hpp>

#include "Hero.h"

class Item
{
public:
    Item(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount, sf::IntRect spriteRect, sf::IntRect effectRect);

    virtual ~Item() = default;

    int getItemCount() const;

    void setItemCount(int itemCount);

    virtual void displayItem(float posX, float posY, sf::RenderTarget &window);

    void displayName(sf::RenderTarget &window, float nameX, float nameY);

    std::wstring getItemName() const;

    std::wstring getItemDescription() const;

    int getItemPrice() const;

    virtual void use(Hero &hero);

    //displaying item icon for shop
    void displayShopItemIcon(sf::Vector2f pos, sf::RenderTarget &window);

    //displaying item name for shop
    void displayShopItemName(sf::Vector2f pos, sf::RenderTarget &window);

    //method to display different items' effects
    void displayEffect(sf::Vector2f pos, sf::RenderTarget &window);//pos must be updated by getting the position of the hero

protected:
    sf::Sprite itemEffectSprite;
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