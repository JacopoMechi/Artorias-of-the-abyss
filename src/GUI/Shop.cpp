#include "Shop.h"

Shop::Shop(sf::RenderWindow &window): Inventory(window){
    //changing error messages for shop class
    if(!texture.loadFromFile("Textures/PlayerHUD.png"))
        std::cout << "Error on loading textures for shop" << std::endl;
    if(!font.loadFromFile("Fonts/pixelFont.ttf"))
        std::cout << "Error on loading text font for shop" << std::endl;

    //we will use invenotrySprite to show shop sprite
    sprite.setTextureRect({shopX, shopY, shopWidth, shopHeight});
    sprite.setPosition({shopPosX, shopPosY});

    //change position of box
    boxSprite.setPosition({shopBoxPosX, shopBoxPosY});
}

void Shop::draw(){
    if(isOpen){
        window.draw(sprite);

        //darwing tracker sprite to select the item we want to buy
        trackerSprite.setPosition(trackerShopPos[tracker]);
        window.draw(trackerSprite);

        //displaying homeward bone and null item, or green blossom and pendant
        items[2 - 1*type] -> displayShopItemIcon({shopItemX, firstShopItemY}, window);//the index can be 1 or 2. Item[1] is green blossom, item[2] is  homeward bone
        items[2 - 1*type] -> displayShopItemName({shopDescriptionX, firstShopDescriptionY}, window);
        items[4 - 1*type] -> displayShopItemIcon({shopItemX, secondShopItemY}, window);//the index can be 4 or 3. item[4] is nullItem, item[3] is pendant
        items[4 - 1*type] -> displayShopItemName({shopDescriptionX, secondShopDescriptionY}, window);

        //drawing box to buy item
        displayBox();

        //to display error message in case the character doesn't have enough money to buy an item
        displayErrorMessage();
    }
}

void Shop::nextItem(){
    tracker = (tracker + 1) % (1+type);//because we have two type of shops: one of chester(only one item) and the other of elizabeth(2 items)
}

void Shop::previousItem(){
    tracker = ((type) + tracker) % (1+type);
}

void Shop::displayBox(){
    if(isBuying){
        window.draw(boxSprite);
        drawText(L"Quanti  ne vuoi acquistare? \n[1] 1     [2] 5     [3]10", {buyingTextX, buyingTextY}, 13);
    }
}

int Shop::getNItem() const{
    if(type == 0 && tracker == 0)
        return 2;//homeward bone
    else if(type == 1 && tracker == 0)
        return 1;//green blossom
    else if(type == 1 && tracker == 1)
        return 3;//pendant
    else{//printing error message in case we don't have the two kinds of npcs that can have shop
        std::cout << "Error: this type of NPC cannot have shop" << std::endl;
        return -1;
    }
}

int Shop::getNPCType() const{
    return type;
}

void Shop::setNPCType(int type){
    this -> type = type;
}

bool Shop::getIsBuying() const{
    return isBuying;
}

void Shop::setIsBuying(bool isBuying){
    this -> isBuying = isBuying;
}

void Shop::purchaseItem(Hero &hero, int amount, Item *item) {
    if(hero.getCash() >= items[getNItem()] -> getItemPrice()*amount){
        item -> setItemCount(item -> getItemCount() + amount);
        hero.setCash(hero.getCash() - items[getNItem()] -> getItemPrice()*amount);
        isBuying = false;
        isError = false;
    }else
        isError = true;
        
}

void Shop::displayErrorMessage(){
    if(isError){
        drawText(L"non hai abbastanza soldi per \nacquistare questo oggetto !", {errorMessX, errorMessY}, 13);
    }
}