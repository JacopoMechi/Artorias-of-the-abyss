#ifndef _ITEM_H
#define _ITEM_H

#include <string>

class Item {
public:
    Item(std::string n, int p, int c, std::string d, int M); // n: itemName, p: itemPrice, c: itemCount, d: itemDescription
                                                     // M:maxItemCount
    ~Item();
protected: 
    std::string itemName;
    int itemPrice;
    int itemCount;
    std::string itemDescription;
    int maxItemCount;
};

#endif //_ITEM_H