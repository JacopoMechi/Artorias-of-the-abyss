#ifndef _PENDANT_H
#define _PENDANT_H

#include "Item.h"

class Pendant: public Item {
public://is it correct the override like this?
    explicit Pendant(std::wstring itemName = L"Pendente", int itemPrice = 10000,
                     std::wstring itemDescription = L"Permette la deviazione \ndelle spells", int maxItemCount = 1, int itemCount = 0,
                     sf::IntRect spriteRect = {498, 99, 23, 17}, sf::IntRect effectRect = {525, 191, 25, 26});
    virtual ~Pendant();
    virtual void displayEffect(sf::Vector2f pos, sf::RenderTarget &window) override;
    virtual void use(Hero& hero) override;
private:
    int immuneTime = 3;
};

#endif //_PENDANT_H