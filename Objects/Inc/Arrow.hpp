#pragma once
#include "GameObject.hpp"
#include "GameManager.hpp"
#include "MoveComponent.hpp"
#include "LifeTimeComponent.hpp"
#include "Debug.hpp"

class Arrow : public GameObject
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
        auto self = getSharedPtr();

        if (other != player_object && dynamic_cast<Arrow*>(other.get()) == nullptr)
        {
            GameManager::getInstance().applyDamage(other, 10, self);
            destroy();
        }
    };

    virtual void registerComponents() override
    {
        Components_.push_back(std::make_shared<MoveComponent>(this, sf::Vector2f{500, 100}, 1500.f));
        Components_.push_back(std::make_shared<LifeTimeComponent>(this, 4.f));
    }

    Arrow(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeW, float sizeH)
        : GameObject{objectName, texture, posX, posY, sizeW, sizeH} {};

    
};