cmake_minimum_required(VERSION 3.0)
project(Artorias-Of-The-Abyss VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_NAME ArtoriasOfTheAbyss)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

include_directories(src)#, GameCharacters, Rooms

add_executable(${EXECUTABLE_NAME}
    main.cpp
    src/Game.h
    src/Game.cpp

    # GameCharacters
    src/GameCharacters/GameCharacter.h
    src/GameCharacters/GameCharacter.cpp
    src/GameCharacters/Hero.h
    src/GameCharacters/Hero.cpp
    src/GameCharacters/NPC.h
    src/GameCharacters/NPC.cpp

    # src/GameCharacters/Enemies/EnemyFactory.h
    # src/GameCharacters/Enemies/EnemyFactory.cpp
    # src/GameCharacters/Enemies/Enemy.h
    # src/GameCharacters/Enemies/Enemy.cpp
    # src/GameCharacters/Enemies/Boss1.h
    # src/GameCharacters/Enemies/Boss1.cpp
    # src/GameCharacters/Enemies/Boss2.h
    # src/GameCharacters/Enemies/Boss2.cpp
    # src/GameCharacters/Enemies/Boss3.h
    # src/GameCharacters/Enemies/Boss3.cpp
    # src/GameCharacters/Enemies/Enemy1.h
    # src/GameCharacters/Enemies/Enemy1.cpp
    # src/GameCharacters/Enemies/Enemy2.h
    # src/GameCharacters/Enemies/Enemy2.cpp
    # src/GameCharacters/Enemies/Enemy3.h
    # src/GameCharacters/Enemies/Enemy3.cpp
    # src/GameCharacters/Enemies/Enemy4.h
    # src/GameCharacters/Enemies/Enemy4.cpp

    # Rooms
    src/Rooms/RoomFactory.h
    src/Rooms/RoomFactory.cpp
    src/Rooms/Room.h
    src/Rooms/Room.cpp
    src/Rooms/StartRoom.h
    src/Rooms/StartRoom.cpp
    src/Rooms/MiddleRoom.h
    src/Rooms/MiddleRoom.cpp
    src/Rooms/FinalRoom.h
    src/Rooms/FinalRoom.cpp

    src/Bonfire.h
    src/Bonfire.cpp
    src/Gate.h
    src/Gate.cpp
    src/Rooms/RoomElement.h
    src/Rooms/RoomElement.cpp
    src/Menu.h
    src/Menu.cpp

    src/Weapon.h
    src/Weapon.cpp
    src/Sword.h
    src/Sword.cpp
    src/Catalyst.h
    src/Catalyst.cpp
    src/Item.cpp
    src/Item.h
    src/HUD.h
    src/HUD.cpp
    src/EstusFlask.h
    src/EstusFlask.cpp
    src/GreenBlossom.h
    src/GreenBlossom.cpp
    src/HomewardBone.h
    src/HomewardBone.cpp
    src/Pendant.h
    src/Pendant.cpp
    src/NullItem.h
    src/NullItem.cpp
    src/CharacterInputs.h
    src/CharacterInputs.cpp
    src/Shop.h
    src/Shop.cpp
    src/Inventory.h
    src/Inventory.cpp)

if(SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)