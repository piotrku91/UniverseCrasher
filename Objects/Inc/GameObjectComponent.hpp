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
    GameObject* Owner_;


protected:
    GameObject* getOwner() {return Owner_;};

public:
    virtual void begin() override {};
    virtual void tick([[maybe_unused]] float delta_time) override {};
    virtual void onCollision([[maybe_unused]] std::shared_ptr<GameObject> &other) override {};
    virtual void onTakeDamage([[maybe_unused]] std::shared_ptr<GameObject> &other, [[maybe_unused]] float damage_amount) override {};

    explicit GameObjectComponent(class GameObject* owner):DestroyFlag_(false), Owner_(owner){};
	virtual ~GameObjectComponent() {};
};