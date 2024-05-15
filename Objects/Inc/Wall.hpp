#pragma once
#include "GameObject.hpp"
#include "GameManager.hpp"
#include "MoveComponent.hpp"
#include "LifeTimeComponent.hpp"
#include "HealthComponent.hpp"
#include "Debug.hpp"

class Wall : public GameObject
{

public:

    virtual void begin() override{
        GameObject::begin();

    };
    
    virtual void tick([[maybe_unused]]float delta_time) override
    {
        GameObject::tick(delta_time);

    };

    virtual void onCollision([[maybe_unused]]std::shared_ptr<GameObject> &other)
    { 
        GameObject::onCollision(other);
        auto player_object = GameManager::getInstance().getPlayerGameObject();

        if (other == player_object)
        {
            auto self = getSharedPtr();

            if (player_object->getPositionAbs().x <= getPositionAbs().x)
            {
            GameManager::getInstance().getPlayerController().setModifierState(ControllerModifierState::RightLock);
            }
            else
            {
            GameManager::getInstance().getPlayerController().setModifierState(ControllerModifierState::LeftLock);   
            }
        }
    };

    virtual void registerComponents() override
    {
       
    }

    Wall(const std::string &objectName, const sf::Texture& texture, float posX, float posY, float sizeW, float sizeH)
        : GameObject{objectName, texture, posX, posY, sizeW, sizeH} {};

    
};