#pragma once
#include "GameObject.hpp"
#include "Controller.hpp"
#include "Debug.hpp"
#include "GameManager.hpp"


class Player : public GameObject, public Controller
{

public:
    virtual void begin() override{};

    virtual void tick(uint32_t delta_time) override
    {
       
    };

    virtual void moveRight() override 
    {
        getObjectRect().x += 1 * GameManager::getInstance().getDeltaTime();
    }

     virtual void moveLeft() override 
    {
        getObjectRect().x -= 1 * GameManager::getInstance().getDeltaTime();
    }

    virtual void onCollision(std::shared_ptr<GameObject> &other)
    { 
        debug("Collision " + getObjectName() + " with " + other->getObjectName());
    };

    Player(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, Color objectColor)
        : GameObject{objectName, posX, posY, sizeW, sizeH, objectColor} {};
};