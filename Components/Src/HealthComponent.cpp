#include "HealthComponent.hpp"
#include "GameManager.hpp"
#include "GameObject.hpp"

void HealthComponent::onTakeDamage([[maybe_unused]] std::shared_ptr<class GameObject>& other, [[maybe_unused]] float damage_amount) {
    Health_ -= damage_amount;
    if (Health_ <= 0) {
        Health_ = 0;
        auto owner_object = getOwner()->getSharedPtr();
        GameManager::getInstance().someObjectDead(owner_object);
    }
}

HealthComponent::HealthComponent(class GameObject* owner, float start_health, float max_health)
    : GameObjectComponent(owner), Health_(start_health), MaxHealth_(max_health) {}