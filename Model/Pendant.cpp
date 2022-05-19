#include "Pendant.h"

Pendant::Pendant(std::wstring itemName, int itemPrice, std::wstring itemDescription, int maxItemCount, int itemCount,
                 int x, int y, int width, int height): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, 
                 x, y, width, height){

}

Pendant::~Pendant(){

}

void Pendant::use(Hero& hero) {//TODO implement hold time
    int tmp = hero.getArmor();
    hero.setArmor(100);
    //wait 3 seconds with immuneTime
    hero.setArmor(tmp);
}