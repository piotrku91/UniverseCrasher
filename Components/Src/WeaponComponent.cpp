#include "WeaponComponent.hpp"
#include "GameManager.hpp"
#include "GameObject.hpp"

WeaponComponent::WeaponComponent(class GameObject *owner, WeaponType weapon_type, int ammo)
    : GameObjectComponent(owner), WeaponType_(weapon_type), Ammo_(ammo) {}

void WeaponComponent::setWeapon(WeaponType weapon)
{
    WeaponType_ = weapon;
}

void WeaponComponent::setAmmo(int ammo_count)
{
    Ammo_ = ammo_count;
}

void WeaponComponent::triggerBullet()
{
    switch (WeaponType_)
    {
    case WeaponType::Arrow:
    {
    
        //GameManager::getInstance().spawnObjectAt(Box{"nowy"}, {50, 50});
        break;
    }
    default:
    {
        break;
    }
    }
}