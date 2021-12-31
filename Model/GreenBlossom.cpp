#include "GreenBlossom.h"

GreenBlossom::GreenBlossom(std::string itemName, int itemPrice, std::string itemDescription, int maxItemCount, int itemCount,
                           int x, int y, int width, int height): Item(itemName, itemPrice, itemDescription, maxItemCount, itemCount, x, y, width, height){

}

GreenBlossom::~GreenBlossom(){

}

/*void GreenBlossom::use(Hero& hero, int newCooldown, int timeEffect) {
    int tmp = hero.getCooldown();
    // for time = timeEffect in seconds
    hero.setCooldown(newCooldown);
    //end time
    hero.setCooldown(tmp);
}*/