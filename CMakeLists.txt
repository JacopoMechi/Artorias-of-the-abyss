cmake_minimum_required(VERSION 3.0)
project(Artorias-Of-The-Abyss VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_NAME ArtoriasOfTheAbyss)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

include_directories(src)

file(COPY src/Textures src/Fonts DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(test)
set(SOURCE_FILES
    src/Game.h
    src/Game.cpp

    src/CharacterInputs.h
    src/CharacterInputs.cpp

    src/achivementsObserver.h
    src/achivementsObserver.cpp

    # GameCharacters
    src/GameCharacters/GameCharacter.h
    src/GameCharacters/GameCharacter.cpp
    src/GameCharacters/Hero.h
    src/GameCharacters/Hero.cpp
    src/GameCharacters/NPC.h
    src/GameCharacters/NPC.cpp

    src/GameCharacters/Enemies/EnemyFactory.h
    src/GameCharacters/Enemies/EnemyFactory.cpp
    src/GameCharacters/Enemies/Enemy.h
    src/GameCharacters/Enemies/Enemy.cpp
    src/GameCharacters/Enemies/Monster.h
    src/GameCharacters/Enemies/Monster.cpp

    # Rooms
    src/Rooms/Room.h
    src/Rooms/Room.cpp
    src/Rooms/RoomElement.h
    src/Rooms/RoomElement.cpp
    src/Rooms/Bonfire.h
    src/Rooms/Bonfire.cpp
    src/Rooms/Gate.h
    src/Rooms/Gate.cpp
    
    src/GUI/Menu.h
    src/GUI/Menu.cpp
    src/GUI/HUD.h
    src/GUI/HUD.cpp
    src/GUI/Shop.h
    src/GUI/Shop.cpp
    src/GUI/Inventory.h
    src/GUI/Inventory.cpp

    src/Weapones/Weapon.h
    src/Weapones/Weapon.cpp
    src/Weapones/Sword.h
    src/Weapones/Sword.cpp
    src/Weapones/Catalyst.h
    src/Weapones/Catalyst.cpp

    src/Items/Item.cpp
    src/Items/Item.h
    src/Items/EstusFlask.h
    src/Items/EstusFlask.cpp
    src/Items/GreenBlossom.h
    src/Items/GreenBlossom.cpp
    src/Items/HomewardBone.h
    src/Items/HomewardBone.cpp
    src/Items/Pendant.h
    src/Items/Pendant.cpp
    src/Items/NullItem.h
    src/Items/NullItem.cpp
    )

add_executable(${EXECUTABLE_NAME} main.cpp ${SOURCE_FILES})

IF(UNIX AND NOT APPLE)
    add_library(core ${SOURCE_FILES})
    target_link_libraries(${EXECUTABLE_NAME} core)
endif()

if(SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)