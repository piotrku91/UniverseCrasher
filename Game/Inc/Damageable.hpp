#pragma once
#include <memory>

class Damageable
{
    virtual void onTakeDamage(std::shared_ptr<class GameObject> &other, float damage_amount) = 0;
};