#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <SFML/Graphics.hpp>

class Item {
public:
    Item(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount, int x, int y, int width, int height); 

    ~Item();

    int getItemCount();

    void setItemCount(int itemCount);

    void displayItem(int posX, int posY, sf::RenderTarget &rt);

protected: 
    std::string itemName;
    int itemPrice;
    int itemCount;
    std::string itemDescription;
    int maxItemCount;
    int x;
    int y;
    int width;
    int height;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif //_ITEM_H