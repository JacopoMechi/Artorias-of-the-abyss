#include "Item.h"

Item::Item(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount, int x, int y, int width, int height) : 
    itemName(itemName), itemPrice(itemPrice), itemDescription(itemDescription), maxItemCount(maxItemCount), itemCount(itemCount), 
    x(x), width(width), height(height){
        texture.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/0x72_DungeonTilesetII_v1.4.png");
        sprite.setTexture(texture);
        sprite.setTextureRect({x, y, width, height});
}

Item::~Item(){

}

int Item::getItemCount() {
    return itemCount;
}

void Item::setItemCount(int itemCount){
    this -> itemCount = itemCount;
}

void Item::displayItem(int posX, int posY, sf::RenderTarget &rt){
    if(this -> getItemCount() > 0){
        //display colored sprite
        sprite.setPosition({posX, posY});
        rt.draw(sprite);
    }else{
        //display gray sprite
        //the rect must be edited
    }
}