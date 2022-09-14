#pragma once
#include "GameObject.hpp"
#include "GameManager.hpp"
#include "MoveComponent.hpp"
#include "Debug.hpp"

class Box : public GameObject
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
            GameManager::getInstance().applyDamage(player_object, 1, self);
        };
    };

    virtual void registerComponents() override
    {
        Components_.push_back(std::make_shared<MoveComponent>(this, sf::Vector2f{500, 1000}, 100));
    }

    Box(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeW, float sizeH)
        : GameObject{objectName, texture, posX, posY, sizeW, sizeH} {};
};