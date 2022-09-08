#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include "Color.hpp"

template <typename T>
std::shared_ptr<T> createObject(T&& args)
{
    return std::make_shared<T>(args);
}

// TO DO: Move functions to cpp file
///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObject
{
protected:
    std::string objectName_;
    SDL_Rect objectRect_;

public:
    virtual SDL_Rect &getObjectRect() { return objectRect_; };
    virtual std::string getObjectName() { return objectName_; };
    virtual void drawObject(SDL_Renderer *renderer) = 0;
    virtual void onCollision(std::shared_ptr<GameObject>& other) {};

    GameObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH)
        : objectName_{objectName}, objectRect_{posX, posY, sizeW, sizeH} {};
};
