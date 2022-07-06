#include "RoomFactory.h"

std::unique_ptr<Room> RoomFactory::makeRoom(std::string type, sf::RenderWindow &window, int roomLevel) const{
    std::unique_ptr<Room> room;
    room = createRoom(type, window, roomLevel);
    
    return room;
}

std::unique_ptr<Room> RoomFactory::createRoom(std::string type, sf::RenderWindow &window, int roomLevel) const{
   if(type.compare("startingroom") == 0){
       return std::unique_ptr<StartRoom>(new StartRoom(roomLevel, window));
   }else if(type.compare("room") == 0){
       return std::unique_ptr<Room>(new Room(roomLevel, window));
   }else if(type.compare("middleroom") == 0){
       return std::unique_ptr<MiddleRoom>(new MiddleRoom(roomLevel, window));
   }else if(type.compare("finalroom") == 0){
       return std::unique_ptr<FinalRoom>(new FinalRoom(roomLevel, window));
   }else return 0;
}