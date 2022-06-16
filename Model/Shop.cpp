#include "Shop.h"

Shop::Shop(sf::RenderWindow &window): Inventory(window){
    //we will use invenotrySprite to show shop sprite
    sprite.setTextureRect({89, 355, 352, 313});
    sprite.setPosition({500, 259});

    //change position of box
    boxSprite.setPosition({1000, 259});
}

void Shop::draw(){
    if(isOpen){
        window.draw(sprite);

        //darwing tracker sprite to select the item we want to buy
        trackerSprite.setPosition(trackerShopPos[tracker]);
        window.draw(trackerSprite);

        //displaying homeward bone and null item, or green blossom and pendant
        items[2 - 1*type] -> displayShopItemIcon({559, 310}, window);//the index can be 1 or 2. Item[1] is green blossom, item[2] is  homeward bone
        items[2 - 1*type] -> displayShopItemName({646, 330}, window);
        items[4 - 1*type] -> displayShopItemIcon({559, 420}, window);//the index can be 4 or 3. item[4] is nullItem, item[3] is pendant
        items[4 - 1*type] -> displayShopItemName({646, 437}, window);

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
        drawText(L"Quanti  ne vuoi acquistare? \n[1] 1     [2] 5     [3]10", {1010, 275}, 13);
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
    if(hero.getMoneyAmount() >= items[getNItem()] -> getItemPrice()*amount){//FIXME item selected
        item -> setItemCount(item -> getItemCount() + amount);
        hero.setMoneyAmount(hero.getMoneyAmount() - items[getNItem()] -> getItemPrice()*amount);//FIXME item selected 
        isBuying = false;
        isError = false;
    }else
        isError = true;
        
}

void Shop::displayErrorMessage(){
    if(isError){
        drawText(L"non hai abbastanza soldi per \nacquistare questo oggetto !", {1010, 310}, 13);
    }
}