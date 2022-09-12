#pragma once

#include <string>
#include <memory>
#include "Tickable.hpp"
#include "Collidable.hpp"
#include "Damageable.hpp"
#include "Debug.hpp"
#include "SFML/Graphics.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObjectComponent : public Tickable, public Collidable, public Damageable
{
private:
    std::string ObjectName_;
    bool DestroyFlag_;
    GameObject* getOwner() {return Owner_;};

protected:
    GameObject* Owner_;

public:
    virtual void begin(){};
    virtual void tick([[maybe_unused]] float delta_time) {};
    virtual void onCollision([[maybe_unused]] std::shared_ptr<GameObject> &other){};
    virtual void onTakeDamage([[maybe_unused]] std::shared_ptr<GameObject> &other, [[maybe_unused]] float damage_amount){};

    GameObjectComponent(class GameObject* owner):Owner_(owner){};
};