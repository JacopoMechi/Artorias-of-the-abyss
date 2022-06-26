#include "FourthRoom.h"

FourthRoom::FourthRoom(int level, sf::RenderWindow &window): Room(level, window){
    switch(level){
        case 1:
            roomFilePath = roomPath1;
            //TODO spawn enemies
            break;
        case 2:
            roomFilePath = roomPath2;
            //TODO spawn enemies
            break;
        case 3:
            roomFilePath = roomPath3;
            //TODO spawn enemies
            break;    
    }
    leftGate = std::make_unique<Gate>(window);
    rightGate = std::make_unique<Gate>(window, true, false);
    bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {500.0f, 500.0f}));
    if(!roomTexture.loadFromFile(roomFilePath))
        std::cout << "Error on loading fourth room's texture" << std::endl;
    roomSprite.setTexture(roomTexture);
}