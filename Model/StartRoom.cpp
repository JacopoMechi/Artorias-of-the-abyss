#include "StartRoom.h"

StartRoom::StartRoom(int level, sf::RenderWindow &window): Room(level, window){
    switch(level){
        case 1:
            roomFilePath = roomPath1;
            //TODOdraw enemies
            break;
        case 2:
            roomFilePath = roomPath2;
            //TODOdraw enemies
            break;
        case 3:
            roomFilePath = roomPath2;
            //TODOdraw enemies
            break;
    }
    rightGate = std::make_unique<Gate>(window, true, false);
}