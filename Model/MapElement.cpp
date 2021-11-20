#include "MapElement.h"

float MapElement::getPosX()
{
    return posX;
}
void MapElement::setPosX(float posX)
{
    this->posX = posX;
}

float MapElement::getPosY()
{
    return posY;
}
void MapElement::setPosY(float posY)
{
    this->posY = posY;
}
MapElement::MapElement(float posX, float posY)
{
    MapElement::setPosX(posX);

    MapElement::setPosY(posY);
}
MapElement::~MapElement() {}