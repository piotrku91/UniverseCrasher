
add_library(ObjectsLib Src/GraphicsObject.cpp Src/SimpleRectangleObject.cpp Src/TexturedObject.cpp Src/Controller.cpp)

target_include_directories(ObjectsLib PUBLIC Inc)