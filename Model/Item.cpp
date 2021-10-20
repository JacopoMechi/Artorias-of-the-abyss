#include "Item.h"

Item::Item(std::string n, int p, int c, std::string d, int M) : itemName(n), itemPrice(p), itemCount(c),
    itemDescription(d), maxItemCount(M){

}

Item::~Item(){

}