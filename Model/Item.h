/**
 * Project Untitled
 */


#ifndef _ITEM_H
#define _ITEM_H

class Item {
public: 
    
/**
 * @param string itemName
 * @param int itemPrice
 * @param int itemCount
 * @param string itemDescription
 */
void showDescription(void string itemName, void int itemPrice, void int itemCount, void string itemDescription);
protected: 
    string itemName;
    int itemPrice;
    int itemCount;
    string itemDescription;
    int maxItemCount;
};

#endif //_ITEM_H