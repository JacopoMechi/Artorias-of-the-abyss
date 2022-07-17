#include "NullItem.h"

NullItem::NullItem(std::wstring itemName, int itemPrice, std::wstring itemDescription,
                       int maxItemCount, int itemCount, sf::IntRect spriteRect, sf::IntRect effectRect): 
                       Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, spriteRect, effectRect){

}

NullItem::~NullItem(){
    
}

void NullItem::displayItem(float posX, float posY, sf::RenderWindow &window){
    //blank because null item
}

void NullItem::use(Hero &hero){
    //blank because null item
}