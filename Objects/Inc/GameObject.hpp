#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include "Color.hpp"
#include "SimpleRectangleObject.hpp"
#include "Tickable.hpp"
#include "Debug.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObject : public SimpleRectangleObject, public Tickable
{
private:
    bool DestroyFlag_;

public:
    virtual void begin() override{};
    virtual void tick(uint32_t delta_time) override{};

    virtual void onCollision(std::shared_ptr<GameObject> &other){};

    void destroy()
    {
        DestroyFlag_ = true;
    }

    bool readyToDestroy()
    {
        return DestroyFlag_;
    }

    GameObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, Color objectColor)
        : SimpleRectangleObject{objectName, posX, posY, sizeW, sizeH, objectColor}, DestroyFlag_(false) { begin(); };
};