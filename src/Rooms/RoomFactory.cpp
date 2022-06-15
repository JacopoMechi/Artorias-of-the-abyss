#include "RoomFactory.h"

std::unique_ptr<Room> RoomFactory::createRoom(sf::RenderWindow &window, int roomLevel) const
{
    std::unique_ptr<Room> room = 0;
    if (roomLevel == 0)
        room = std::unique_ptr<StartRoom>(new StartRoom(roomLevel, window));
    else if (roomLevel == 1 or roomLevel == 5 or roomLevel == 9)
        room = std::unique_ptr<SecondRoom>(new SecondRoom(roomLevel, window));
    else if (roomLevel == 2 or roomLevel == 6 or roomLevel == 10)
        room = std::unique_ptr<ThirdRoom>(new ThirdRoom(roomLevel, window));
    else if (roomLevel == 3 or roomLevel == 7 or roomLevel == 11)
        room = std::unique_ptr<FourthRoom>(new FourthRoom(roomLevel, window));
    else if (roomLevel == 4 or roomLevel == 8 or roomLevel == 12)
        room = std::unique_ptr<FinalRoom>(new FinalRoom(roomLevel, window));
    return room;
}