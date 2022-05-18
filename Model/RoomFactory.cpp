#include "RoomFactory.h"

std::unique_ptr<Room> RoomFactory::makeRoom(std::string type, sf::RenderWindow &window, int roomLevel) const{
    std::unique_ptr<Room> room;
    room = createRoom(type, window, roomLevel);
    
    return room;
}

std::unique_ptr<Room> RoomFactory::createRoom(std::string type, sf::RenderWindow &window, int roomLevel) const{
   if(type.compare("startingroom") == 0){
       return std::unique_ptr<StartRoom>(new StartRoom(roomLevel, window));
   }else if(type.compare("secondroom") == 0){
       return std::unique_ptr<SecondRoom>(new SecondRoom(roomLevel, window));
   }else if(type.compare("thirdroom") == 0){
       return std::unique_ptr<ThirdRoom>(new ThirdRoom(roomLevel, window));
   }else if(type.compare("fourthroom") == 0){
       return std::unique_ptr<FourthRoom>(new FourthRoom(roomLevel, window));
   }else if(type.compare("finalroom") == 0){
       return std::unique_ptr<FinalRoom>(new FinalRoom(roomLevel, window));
   }else return 0;
}