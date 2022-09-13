#pragma once

#include "GameObjectComponent.hpp"

class MoveComponent : public GameObjectComponent
{
private:
   sf::Vector2f StartPosition_;
   sf::Vector2f EndPosition_;
   float Speed_;

public:
    void begin() override;
    void tick(float delta_time) override;

    MoveComponent(class GameObject *owner, sf::Vector2f end_position, float speed):GameObjectComponent(owner), EndPosition_(end_position), Speed_(speed){};
};