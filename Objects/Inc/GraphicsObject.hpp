#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include "Color.hpp"
#include "Maths.hpp"

// TO DO: Move functions to cpp file
///////////////////////////////////////////////////////////////////////////////////////////////////////

class GraphicsObject
{
protected:
    std::string ObjectName_;
    Vector2d Position_;
    Size Size_;
    SDL_Rect ObjectRect_;

public:
    const SDL_Rect &getObjectRect() { return ObjectRect_; };
    inline Vector2d getPosition() { return Position_; };
    void setPosition(Vector2d new_position);
    inline Size getSize() const {return Size_;};
    void setSize(Size new_size);


    std::string getObjectName() { return ObjectName_; };
    virtual void drawObject(SDL_Renderer *renderer) = 0;

    GraphicsObject(const std::string &objectName, Vector2d position, Size size)
        : ObjectName_{objectName}, Position_{position}, Size_{size}, ObjectRect_{Position_.getX(), Position_.getY(), Size_.width, Size_.height} {};
};

