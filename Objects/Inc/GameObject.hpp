#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include "Color.hpp"
#include "SimpleRectangleObject.hpp"
#include "Debug.hpp"


///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObject: public SimpleRectangleObject
{
private:
    bool DestroyFlag_;

public:
    virtual void onCollision(std::shared_ptr<GameObject>& other) { // Only temporary for test
        debug("Collision "+getObjectName()+" with"+other->getObjectName()); 
        
        if (other->getObjectName() == "Player") {
        destroy();
        };
    };

    void destroy() {
        DestroyFlag_ = true;
    }

    bool readyToDestroy()
    {
        return DestroyFlag_;
    }

    GameObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, Color objectColor)
        : SimpleRectangleObject{objectName, posX, posY, sizeW, sizeH, objectColor}, DestroyFlag_(false) {};

};