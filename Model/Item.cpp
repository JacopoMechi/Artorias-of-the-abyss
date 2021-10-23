#include "Item.h"

Item::Item(std::string n, int p, std::string d, int M, int c) : itemName(n), itemPrice(p),
    itemDescription(d), maxItemCount(M), itemCount(c){

}

Item::~Item(){

}

int Item::getItemCount() {
    return itemCount;
}

void Item::setItemCount(int itemCount){
    this -> itemCount = itemCount;
}