#include "Gate.h"
#include <SFML/System.hpp>
#include <string>
#include <vector>

bool Gate::getisOpen()
{
    return isOpen;
}

void Gate::setisOpen(bool isOpen) //TODO implement graphic change for open or close
{
    this->isOpen = isOpen;
}

Gate::Gate(std::vector<int> &spriteDimension, sf::Vector2f &position, std::string &mapElementFilePath, bool isOpen) : MapElement(spriteDimension, position, mapElementFilePath), isOpen(isOpen) {}

Gate::~Gate() {}