#pragma once

#include <string>
#include <memory>
#include "Color.hpp"
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
    virtual void tick(uint32_t delta_time) {};
    virtual void onCollision(std::shared_ptr<GameObject> &other){};
    virtual void onTakeDamage(std::shared_ptr<GameObject> &other, float damage_amount){};

    GameObjectComponent(class GameObject* owner):Owner_(owner){};
};