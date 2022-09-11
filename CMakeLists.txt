cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(UniverseCrasher)

set(FLAGS -Wall -Wextra -Wconversion -pedantic -pedantic-errors -g)

add_compile_options(${FLAGS})

set(SFML_DIR "./libs/SFML-2.5.1/lib/cmake/SFML")
set(SFML_TARGETS sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories(${PROJECT_NAME} PUBLIC "./libs/SFML-2.5.1/include/")
include_directories(${PROJECT_NAME} PUBLIC Utilities)
add_subdirectory(Drawing)
add_subdirectory(Objects)
add_subdirectory(Game)

#enable_testing()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(DrawingLib ObjectsLib)
target_link_libraries(GameManager DrawingLib)
target_link_libraries(
    ${PROJECT_NAME}
    ${SFML_TARGETS}
    ObjectsLib
    DrawingLib
    GameManager
)

#add_executable(${PROJECT_NAME}-ut test.cpp Player.cpp Cards.hpp)
#target_link_libraries(${PROJECT_NAME}-ut gtest_main)

#add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)