#include "EstusFlask.h"

EstusFlask::EstusFlask(std::wstring itemName, int itemPrice, std::wstring itemDescription,
                       int maxItemCount, int itemCount, int x, int y, int width, int height): 
                       Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, x, y, width, height){

}

EstusFlask::~EstusFlask(){

}

void EstusFlask::use(Hero& hero) {
    if (itemCount > 0){
        itemCount--;
        hero.setHp(hero.getHp()+healthRestored);
    }
}