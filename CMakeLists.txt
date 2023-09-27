cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(UniverseCrasher)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(FLAGS /MP4)
else()
    set(FLAGS -Wall -Wextra -Wconversion -pedantic -pedantic-errors -g)
endif()
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
add_compile_options(${FLAGS})

set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")
set(SFML_TARGETS sfml-system sfml-window sfml-graphics sfml-network sfml-audio)


include_directories(${PROJECT_NAME} PUBLIC "libs/SFML-2.5.1/include/")
include_directories(${PROJECT_NAME} PUBLIC Utilities)
add_subdirectory(Components)
add_subdirectory(Drawing)
add_subdirectory(Objects)
add_subdirectory(Game)


                         

#enable_testing()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(ObjectsLib GameManager)
target_link_libraries(ObjectsLib Components)
target_link_libraries(Components ObjectsLib)

target_link_libraries(DrawingLib ObjectsLib)
target_link_libraries(GameManager DrawingLib)
target_link_libraries(
    ${PROJECT_NAME}
    ${SFML_TARGETS}
    ObjectsLib
    DrawingLib
    GameManager
    Components
)

#add_executable(${PROJECT_NAME}-ut test.cpp Player.cpp Cards.hpp)
#target_link_libraries(${PROJECT_NAME}-ut gtest_main)

#add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)