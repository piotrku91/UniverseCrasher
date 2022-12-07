#include "WeaponComponent.hpp"
#include "GameManager.hpp"
#include "GameObject.hpp"
#include "Balloon.hpp"
#include "Arrow.hpp"

WeaponComponent::WeaponComponent(class GameObject *owner, WeaponType weapon_type, int ammo, float spawn_delay)
    : GameObjectComponent(owner), WeaponType_(weapon_type), Ammo_(ammo), LastSpawnTime_(0), SpawnDelay_(spawn_delay) {}

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
    float now = GameManager::getInstance().getTimeFromStartS();
    if (now - LastSpawnTime_ < SpawnDelay_ || Ammo_ == 0) {return;};

    switch (WeaponType_)
    {
    case WeaponType::Arrow:
    {
        Arrow* new_arrow;
        sf::Vector2f player_position = GameManager::getInstance().getPlayerGameObject()->getPositionAbs();
        GameManager::getInstance().spawnObjectAt(new_arrow, sf::Vector2f{player_position.x, player_position.y - 30}, 5, 5);
        LastSpawnTime_ = now;
        Ammo_--;
        break;
    }
    default:
    {
        break;
    }
    }
}