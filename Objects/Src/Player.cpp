#include "Player.hpp"
#include "HealthComponent.hpp"

void Player::begin() {
    GameObject::begin();
}

void Player::tick([[maybe_unused]] float delta_time) {
    GameObject::tick();
}

void Player::onCollision(std::shared_ptr<GameObject> &other)
{
    GameObject::onCollision(other);
    debug("Collision " + getObjectName() + " with " + other->getObjectName());
}

Player::Player(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeW, float sizeH)
    : GameObject{objectName, texture, posX, posY, sizeW, sizeH}
{
}

void Player::registerComponents()
{
Components_.push_back(std::make_shared<HealthComponent>(this, 100, 100));
}