
#include "Room.h"

Room::Room(int level, sf::RenderWindow &window): level(level), window(window){
    switch(level){
        case 1:
            roomFilePath = roomPath1;
            //TODO draw enemies
            break;
        case 2:
            roomFilePath = roomPath2;
            //TODO draw enemies
            break;
        case 3:
            roomFilePath = roomPath3;
            //TODO draw enemies
            break;
    }
    npc = std::unique_ptr<NPC>(nullptr);
    leftGate = std::make_unique<Gate>(window);
    rightGate = std::make_unique<Gate>(window, true, false);
    bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {500.0f, 500.0f}));
    if(!roomTexture.loadFromFile(roomFilePath))
        std::cout << "Error on loading second room's texture" << std::endl;
    roomSprite.setTexture(roomTexture);
}

void Room::spawnEntity(RoomElement *roomElement)
{
    roomElementsVector.emplace_back(roomElement);
}

bool Room::getisClear()
{
    return isClear;
}

void Room::draw()
{
    roomSprite.setTextureRect({0, 0, 1920, 1080});
    window.draw(roomSprite);
    if (leftGate != nullptr)
        leftGate->draw();
    if (rightGate != nullptr)
        rightGate->draw();
    if (bonfire != nullptr)
        bonfire->draw();
    if (npc != nullptr)
        npc->draw(window);
}

Bonfire* Room::getBonfire(){
    return bonfire.get();
}

NPC* Room::getNPC(){
    return npc.get();
}