#pragma once
#include "GameObjectComponent.hpp"

class LifeTimeComponent : public GameObjectComponent
{
private:
    float BornTime_;
    float MaxLifeTime_;

public:
    float getMaxLifeTime() const { return MaxLifeTime_; };

    void begin() override;
    void tick(float delta_time) override;

    LifeTimeComponent(class GameObject *owner, float max_life_time);
};