#include "NullItem.h"

NullItem::NullItem(std::wstring itemName, int itemPrice, std::wstring itemDescription,
                       int maxItemCount, int itemCount, int x, int y, int width, int height): 
                       Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, x, y, width, height){

}

NullItem::~NullItem(){
    
}

void NullItem::displayItem(float posX, float posY, sf::RenderTarget &window){
    //blank because null item
}

void NullItem::use(Hero &hero){
    //blank because null item
}