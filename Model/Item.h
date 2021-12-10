#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <SFML/Graphics.hpp>

class Item {
public:
    Item(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount, float x, float y, int width, int height); 

    ~Item();

    int getItemCount();

    void setItemCount(int itemCount);

    void displayItem(float posX, float posY, sf::RenderTarget &rt, float nameX, float nameY);

    std::string getItemName();

    std::string getItemDescription();

protected: 
    std::string itemName;
    int itemPrice;
    int itemCount;
    std::string itemDescription;
    int maxItemCount;
    float x;
    float y;
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