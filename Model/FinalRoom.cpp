#include "FinalRoom.h"

FinalRoom::FinalRoom(int level, sf::RenderWindow &window): Room(level, window){
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
}