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

    virtual void move(int dX, int dY) override
    {
        Controller::move(dX, dY);
        if (CanMove_)
        {
            int delta_time = static_cast<int>(GameManager::getInstance().getDeltaTime());
            setPosition({getPosition().getX() + (dX * delta_time), getPosition().getY() + (dY * delta_time)});
        }
    };

    virtual void onCollision(std::shared_ptr<GameObject> &other)
    {
        debug("Collision " + getObjectName() + " with " + other->getObjectName());
    };

    Player(const std::string &objectName, Vector2d position, Size size, Color objectColor)
        : GameObject{objectName, position, size, objectColor} {};
};