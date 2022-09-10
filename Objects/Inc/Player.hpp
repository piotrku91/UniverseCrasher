#pragma once
#include "GameObject.hpp"
#include "Debug.hpp"

class Player : public GameObject
{

public:
    virtual void begin() override{};

    virtual void tick(uint32_t delta_time) override
    {
        getObjectRect().x += 1 * delta_time;
    };

    virtual void onCollision(std::shared_ptr<GameObject> &other)
    { 
        debug("Collision " + getObjectName() + " with " + other->getObjectName());
    };

    Player(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, Color objectColor)
        : GameObject{objectName, posX, posY, sizeW, sizeH, objectColor} {};
};