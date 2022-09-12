#pragma once
#include "GameObjectComponent.hpp"

class HealthComponent : public GameObjectComponent
{
private:
    float Health_;
    float MaxHealth_;

public:
    float getHealth() const { return Health_; };
    float getMaxHealth() const { return MaxHealth_; };

    void onTakeDamage([[maybe_unused]] std::shared_ptr<class GameObject> &other, [[maybe_unused]] float damage_amount) override;

    HealthComponent(class GameObject *owner, float start_health, float max_health);
};