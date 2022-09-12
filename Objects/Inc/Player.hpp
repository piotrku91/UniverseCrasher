#pragma once
#include "GameObject.hpp"
#include "Controller.hpp"
#include "Debug.hpp"
#include "GameManager.hpp"

class Player : public GameObject, public Controller
{

public:
    virtual void begin() override{};

    virtual void tick(uint32_t delta_time) override{

    };

    virtual void move(float dX, float dY) override
    {
        Controller::move(dX, dY);
            float delta_time = GameManager::getInstance().getDeltaTime();
            sf::Vector2f velocity = {dX, dY};
            Sprite_.move(velocity * delta_time * Speed_);
           
    };

    virtual void onCollision(std::shared_ptr<GameObject> &other)
    {
        debug("Collision " + getObjectName() + " with " + other->getObjectName());
    };

    Player(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeX, float sizeY)
        : GameObject{objectName, texture, posX, posY, sizeX, sizeY} {
            Components_.push_back(createObject<GameObjectComponent>(this));

        };
};