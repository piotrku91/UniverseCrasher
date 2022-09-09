#pragma once
#include "Scene.hpp"

class SceneFirst : public Scene
{
    public:
    SceneFirst(GameObjectsList& game_objects_list):Scene(game_objects_list){};

    void begin() override;
    void tick() override;
};