#include "Pendant.h"

Pendant::Pendant(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount,
                 int x, int y, int width, int height): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, 
                 x, y, width, height){

}

Pendant::~Pendant(){

}

void Pendant::use(Hero& hero) {//TODO implement hold time
    int tmp = hero.getArmor();
    hero.setArmor(100);
    std::cout << "I am strong!" << std::endl;
    //wait 3 seconds with immuneTime
    hero.setArmor(tmp);
}