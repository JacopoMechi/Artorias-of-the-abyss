#include "MiddleRoom.h"

MiddleRoom::MiddleRoom(int level, sf::RenderWindow &window): Room(level, window){
    switch(level){
        case 1:
            roomFilePath = roomPath1;
            npc = std::unique_ptr<NPC>(new NPC(window, 1, {300, 300}, 1, 1, 0, 0));//Elizabeth
            break;
        case 2:
            roomFilePath = roomPath2;
            npc = std::unique_ptr<NPC>(new NPC(window, 0, {300, 300}, 1, 1, 0, 0));//Chester
            break;
        case 3:
            roomFilePath = roomPath3;
            npc = std::unique_ptr<NPC>(new NPC(window, 3, {300, 300}, 1, 1, 0, 0));//Sif
            break;
    }
    leftGate = std::make_unique<Gate>(window);
    rightGate = std::make_unique<Gate>(window, true, false);
    bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {900.0f, 200.0f}));
    if(!roomTexture.loadFromFile(roomFilePath))
        std::cout << "Error on loading second room's texture" << std::endl;
    roomSprite.setTexture(roomTexture);
}