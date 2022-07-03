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

    virtual void displayItem(float posX, float posY, sf::RenderWindow &window);

    void displayName(sf::RenderWindow &window, float nameX, float nameY);

    std::wstring getItemName() const;

    std::wstring getItemDescription() const;

    int getItemPrice() const;

    virtual void use(Hero &hero);

    //displaying item icon for shop
    void displayShopItemIcon(sf::Vector2f pos, sf::RenderWindow &window);

    //displaying item name for shop
    void displayShopItemName(sf::Vector2f pos, sf::RenderWindow &window);

    //method to display different items' effects
    virtual void displayEffect(sf::Vector2f pos, sf::RenderWindow &window);

    //implementing time for displaying times effect
    void effectTime(float dt);

    //implementing time for consumable's effect
    virtual void consumableEffectTime(float dt, Hero &hero, sf::RenderWindow &window);

protected:
    sf::Sprite itemEffectSprite;
    sf::Text shopItemText; //to display item name in shop
    sf::Sprite shopItemSprite; //to display the item in shop
    sf::IntRect coloredSprite;
    std::wstring itemName;
    bool startEffect = true; //to start displaying item for a period of time
    float timeEffect = 0.0f; //counter time
    float startConsumable = true;//to start consumable's effect for a period of time
    float consumableTimeEffect = 0.0f;
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