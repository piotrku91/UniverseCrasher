cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(UniverseCrasher)

set(FLAGS -Wall -Wextra -Wconversion -pedantic -pedantic-errors -g)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on WindowDrawManagers
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


add_compile_options(${FLAGS})

find_package(SDL2 REQUIRED)
include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS})
include_directories(${PROJECT_NAME} PUBLIC Utilities)
add_subdirectory(Drawing)
add_subdirectory(GameObjects)
add_subdirectory(Game)

#enable_testing()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(DrawingLib GameObjectsLib)
target_link_libraries(GameManager DrawingLib)
target_link_libraries(
    ${PROJECT_NAME}
    GL
    SDL2
    SDL2_image
    GameObjectsLib
    DrawingLib
    GameManager
)

#add_executable(${PROJECT_NAME}-ut test.cpp Player.cpp Cards.hpp)
#target_link_libraries(${PROJECT_NAME}-ut gtest_main)

#add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)