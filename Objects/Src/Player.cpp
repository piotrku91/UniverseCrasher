#include "Player.hpp"
#include "HealthComponent.hpp"
#include "WeaponComponent.hpp"

void Player::begin() {
    GameObject::begin();
}

void Player::tick([[maybe_unused]] float delta_time) {
    GameObject::tick(delta_time);
}

void Player::onCollision(std::shared_ptr<GameObject> &other) {
    GameObject::onCollision(other);
    debug("Collision " + getObjectName() + " with " + other->getObjectName());
}

Player::Player(const std::string &objectName, const sf::Texture &texture,
               float posX, float posY, float sizeW, float sizeH)
        : GameObject{objectName, texture, posX, posY, sizeW, sizeH} {
    debug("player spawned");
}

void Player::registerComponents() {
    Components_.push_back(std::make_shared<HealthComponent>(this, 100.f, 100.f));
    Components_.push_back(
            std::make_shared<WeaponComponent>(this, WeaponType::Arrow, 50, 0.3f));
}

void Player::Fire() {
    dynamic_cast<WeaponComponent *>(Components_[1].get())->triggerBullet();
}