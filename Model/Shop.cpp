#include "Shop.h"

Shop::Shop(sf::RenderWindow &window): Inventory(window){
    //we will use invenotrySprite to show shop sprite
    sprite.setTextureRect({89, 355, 352, 313});
    sprite.setPosition({500, 259}); //TODO to be determined
    sprite.setScale({1.5f, 1.5f});

    //
}

void Shop::draw(){
    if(isOpen){
        window.draw(sprite);
    }
}

void Shop::purchaseItem() {

}