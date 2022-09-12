#pragma once
#include <memory>

class Damageable
{
    virtual void onTakeDamage([[maybe_unused]] std::shared_ptr<class GameObject> &other, [[maybe_unused]] float damage_amount) = 0;
};