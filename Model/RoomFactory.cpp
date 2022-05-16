#include "RoomFactory.h"

Room* RoomFactory::makeRoom(std::string type, sf::RenderWindow &window, int roomLevel) const{
    Room* room;
    room = createRoom(type, window, roomLevel);
    
    return room;
}

Room* RoomFactory::createRoom(std::string type, sf::RenderWindow &window, int roomLevel) const{
   if(type.compare("startingroom") == 0){
       return new StartRoom(roomLevel, window);
   }else if(type.compare("secondroom") == 0){
       return new SecondRoom(roomLevel, window);
   }else if(type.compare("thirdroom") == 0){
       return new ThirdRoom(roomLevel, window);
   }else if(type.compare("fourthroom") == 0){
       return new FourthRoom(roomLevel, window);
   }else if(type.compare("finalroom") == 0){
       return new FinalRoom(roomLevel, window);
   }else return 0;
}