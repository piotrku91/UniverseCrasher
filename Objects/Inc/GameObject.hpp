#pragma once

#include <memory>
#include <string>
#include <functional>

#include "Tickable.hpp"
#include "Collidable.hpp"
#include "Damageable.hpp"
#include "Debug.hpp"
#include "Defines.h"
#include "SFML/Graphics.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObject : public Tickable, public Collidable, public Damageable, public std::enable_shared_from_this<GameObject> {
private:
    std::string ObjectName_;

    bool DestroyFlag_;

protected:
    sf::Sprite Sprite_;
    GameObjectsComponentsList Components_;

public:
    virtual void begin() override;
    virtual void tick([[maybe_unused]] float delta_time) override;

    virtual void onCollision(std::shared_ptr<class GameObject>& other) override;
    virtual void onTakeDamage(std::shared_ptr<class GameObject>& other, float damage_amount);

    void setPositionInc(sf::Vector2f position);
    void setPositionAbs(sf::Vector2f position);

    sf::Sprite& getSprite();
    std::string getObjectName();
    std::shared_ptr<GameObject> getSharedPtr();
    sf::Vector2f getPositionAbs();
    
    void destroy();
    bool readyToDestroy();

    GameObject(const std::string& objectName, const sf::Texture& texture, float posX, float posY, [[maybe_unused]] float sizeW, [[maybe_unused]] float sizeH);
    virtual void registerComponents();

private:
    void callInAllComponents(std::function<void(std::shared_ptr<class GameObjectComponent>)> callback);
};
