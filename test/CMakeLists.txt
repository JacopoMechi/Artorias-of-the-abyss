IF(UNIX AND NOT APPLE)
    cmake_minimum_required(VERSION 3.0)

    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    set(SOURCE_FILES runAllTests.cpp EntitiesInteractionsTest.cpp)
    add_executable(runFightingTest ${SOURCE_FILES})
    target_link_libraries(runFightingTest ${GTEST_BOTH_LIBRARIES} core sfml-graphics sfml-window sfml-system)
    file(COPY ../src/Textures ../src/Fonts DESTINATION ${CMAKE_BINARY_DIR})
endif()