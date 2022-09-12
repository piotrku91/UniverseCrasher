#pragma once

#include <string>
#include <memory>
#include "Color.hpp"
#include "Tickable.hpp"
#include "Collidable.hpp"
#include "Damageable.hpp"
#include "GameObjectComponent.hpp"
#include "Debug.hpp"
#include "SFML/Graphics.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObject : public Tickable, public Collidable, public Damageable
{
private:
    std::string ObjectName_;

    bool DestroyFlag_;

protected:
    sf::Sprite Sprite_;
    GameObjectsComponentsList Components_;

public:
    virtual void begin() override
    {
        callInAllComponents([this](auto comp)
                            { comp->begin(); });
    };
    virtual void tick(uint32_t delta_time) override
    {
        callInAllComponents([this, delta_time](auto comp)
                            { comp->tick(delta_time); });
    };

    virtual void onCollision(std::shared_ptr<GameObject> &other) override
    {
        callInAllComponents([this, &other](auto comp)
                            { comp->onCollision(other); });
    };
    virtual void onTakeDamage(std::shared_ptr<class GameObject> &other, float damage_amount)
    {
        callInAllComponents([this, &other, damage_amount](auto comp)
                            { comp->onTakeDamage(other, damage_amount); });
    };
    
    sf::Sprite &getSprite() { return Sprite_; };
    std::string getObjectName() { return ObjectName_; };

    void destroy()
    {
        DestroyFlag_ = true;
    }

    bool readyToDestroy()
    {
        return DestroyFlag_;
    }

    GameObject(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeX, float sizeY)
        : ObjectName_(objectName), DestroyFlag_(false)
    {
        Sprite_ = sf::Sprite(texture, sf::IntRect(0, 0, sizeX, sizeY));
        Sprite_.setPosition(posX, posY);
        Sprite_.setOrigin(sf::Vector2f(15, 0));
        begin();
    };

    void callInAllComponents(std::function<void(std::shared_ptr<GameObjectComponent>)> callback)
    {
        for (auto &comp : Components_)
        {
            callback(comp);
        };
    };
};