#include "Gate.h"

bool Gate::getisOpen()
{
    return isOpen;
}

void Gate::setisOpen(bool isOpen)
{
    this->isOpen = isOpen;
}

Gate::Gate(float posX, float posY, bool isOpen) : MapElement(posX, posY), isOpen(isOpen) {}

Gate::~Gate() {}