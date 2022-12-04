#pragma once
#include "GameObjectComponent.hpp"
#include "WeaponType.hpp"

class WeaponComponent : public GameObjectComponent
{
    private:
    WeaponType WeaponType_;
    int Ammo_;
    float LastSpawnTime_;
    float SpawnDelay_;

public:

    void setWeapon(WeaponType weapon);
    void setAmmo(int ammo_count);

    void triggerBullet();

    WeaponComponent(class GameObject *owner, WeaponType weapon_type, int ammo, float spawn_delay);
};