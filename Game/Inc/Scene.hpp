#pragma once
#include <memory>
#include "Defines.h"

class Scene
{
    protected:
    GameObjectsList& GameObjectsList_;

    public:
    Scene(GameObjectsList& game_objects_list):GameObjectsList_(game_objects_list){};

    virtual void begin() = 0;
    virtual void tick() = 0;
};