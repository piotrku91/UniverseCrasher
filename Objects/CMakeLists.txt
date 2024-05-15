
add_library(ObjectsLib Src/GameObject.cpp Src/Controller.cpp Src/Player.cpp
        Src/Balloon.cpp
        Src/Balloon.cpp)

target_include_directories(ObjectsLib PUBLIC Inc)