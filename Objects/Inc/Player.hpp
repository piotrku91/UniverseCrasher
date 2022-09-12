#pragma once
#include "GameObject.hpp"
#include "Debug.hpp"
#include "GameManager.hpp"

class Player : public GameObject
{

public:
    virtual void begin() override{};

    virtual void tick([[maybe_unused]] float delta_time) override{

    };

    virtual void onCollision(std::shared_ptr<GameObject> &other)
    {
        debug("Collision " + getObjectName() + " with " + other->getObjectName());
    };

    Player(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeX, float sizeY)
        : GameObject{objectName, texture, posX, posY, sizeX, sizeY}
    {
        Components_.push_back(createObject<GameObjectComponent>(this));
    };
};