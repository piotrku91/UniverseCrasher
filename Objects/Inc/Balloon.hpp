#pragma once

#include "GameObject.hpp"
#include "GameManager.hpp"
#include "MoveComponent.hpp"
#include "LifeTimeComponent.hpp"
#include "HealthComponent.hpp"
#include "Debug.hpp"

class Balloon : public GameObject
{

public:
    void begin() override;
    void tick([[maybe_unused]]float delta_time) override;
    void onCollision([[maybe_unused]]std::shared_ptr<GameObject> &other) override;
    void registerComponents() override;

    Balloon(const std::string &objectName, const sf::Texture& texture, float posX, float posY, float sizeW, float sizeH);
};

