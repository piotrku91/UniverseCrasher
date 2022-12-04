#include "LifeTimeComponent.hpp"
#include "GameManager.hpp"
#include "GameObject.hpp"

LifeTimeComponent::LifeTimeComponent(class GameObject* owner, float max_life_time)
    : GameObjectComponent(owner), BornTime_(0), MaxLifeTime_(max_life_time) {}

void LifeTimeComponent::begin() {
    BornTime_ = GameManager::getInstance().getTimeFromStartS();
}

void LifeTimeComponent::tick([[maybe_unused]] float delta_time) {
    if (GameManager::getInstance().getTimeFromStartS() - BornTime_ > MaxLifeTime_)
    {
        auto owner_object = getOwner()->getSharedPtr();
        GameManager::getInstance().someObjectDead(owner_object);
    }
}