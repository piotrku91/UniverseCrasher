#pragma once
#include "GameObject.hpp"
#include "GameManager.hpp"
#include "Debug.hpp"

class Box : public GameObject
{

public:
    virtual void begin() override{};
    
    virtual void tick([[maybe_unused]]float delta_time) override
    {

    };

    virtual void onCollision([[maybe_unused]]std::shared_ptr<GameObject> &other)
    { 
        auto player_object = GameManager::getInstance().getPlayerGameObject();

        if (other == player_object)
        {
            auto self = getSharedPtr();
            GameManager::getInstance().applyDamage(player_object, 1, self);
        };
    };

    Box(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeW, float sizeH)
        : GameObject{objectName, texture, posX, posY, sizeW, sizeH} {};
};