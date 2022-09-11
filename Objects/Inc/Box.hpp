#pragma once
#include "GameObject.hpp"
#include "GameManager.hpp"
#include "Debug.hpp"

class Box : public GameObject
{

public:
    virtual void begin() override{};
    
    virtual void tick(uint32_t delta_time) override
    {

    };

    virtual void onCollision(std::shared_ptr<GameObject> &other)
    { 
        auto player_object = GameManager::getInstance().getPlayerGameObject();

        if (other == player_object)
        {
            destroy();
        };
    };

    Box(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeX, float sizeY)
        : GameObject{objectName, texture, posX, posY, sizeX, sizeY} {};
};