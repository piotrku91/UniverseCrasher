#pragma once

#include <string>
#include <memory>
#include "Tickable.hpp"
#include "Collidable.hpp"
#include "Damageable.hpp"
#include "Debug.hpp"
#include "Defines.h"
#include "SFML/Graphics.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObject : public Tickable, public Collidable, public Damageable, public std::enable_shared_from_this<GameObject>
{
private:
    std::string ObjectName_;

    bool DestroyFlag_;

protected:
    sf::Sprite Sprite_;
    GameObjectsComponentsList Components_;

    std::shared_ptr<GameObject> getSharedThis();

public:
    virtual void begin() override;
    virtual void tick([[maybe_unused]] float delta_time) override;

    virtual void onCollision(std::shared_ptr<class GameObject> &other) override;
    virtual void onTakeDamage(std::shared_ptr<class GameObject> &other, float damage_amount);
    
    void setPositionInc(sf::Vector2f position);
    void setPositionAbs(sf::Vector2f position);

    sf::Sprite &getSprite();
    std::string getObjectName();
    void destroy();

    bool readyToDestroy();

    GameObject(const std::string &objectName, const sf::Texture &texture, float posX, float posY, [[maybe_unused]] float sizeX, [[maybe_unused]] float sizeY);

private:
    void callInAllComponents(std::function<void(std::shared_ptr<class GameObjectComponent>)> callback);
};