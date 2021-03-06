#ifndef _SHOP_H
#define _SHOP_H

#include "Inventory.h"

class Shop: public Inventory {
public:
    Shop(sf::RenderWindow &window);
    
    //drawing shop's interface
    virtual void draw() override;

    //getter and setter to open shop are in invetory's base class

    //overriding page switching system of iventory
    virtual void nextItem() override;
    virtual void previousItem() override;

    //overriding display box of inventory
    virtual void displayBox() override;

    //getter of tracker for getting item
    int getNItem() const;

    //getting type of npc and save the value to know which shop to open
    int getNPCType() const;
    void setNPCType(int type);

    //getter and setter for displaying box
    bool getIsBuying() const;
    void setIsBuying(bool isBuying);

    //to purchase items from shop
    void purchaseItem(Hero &hero, int amount, Item *item);

    //to display error message in case hero cannot buy an item
    void displayErrorMessage();

private:
    int type = -1;//default value which indicates no NPCs

    //setting pos for highlight tracker in shop
    sf::Vector2f trackerShopPos[2] = {{trackedItemX, firstTrackedItemY}, {trackedItemX, secondTrackedItemY}};

    //boolean value to open buying box
    bool isBuying = false;

    //boolean value to display error message
    bool isError = false;

};

#endif //_SHOP_H