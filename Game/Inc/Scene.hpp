#pragma once
#include <memory>
#include "Tickable.hpp"
#include "Defines.h"

class Scene : public Tickable
{
    protected:
    GameObjectsList& GameObjectsList_;

    public:
    Scene(GameObjectsList& game_objects_list):GameObjectsList_(game_objects_list){};

};