#include "GameObject.hpp"

#include <utility>
#include "GameObjectComponent.hpp"
#include "GameManager.hpp"

std::shared_ptr<GameObject> GameObject::getSharedPtr() {
    return shared_from_this();
}

void GameObject::begin() {
    callInAllComponents([](auto comp) { comp->begin(); });
}

void GameObject::tick([[maybe_unused]] float delta_time) {
    callInAllComponents([delta_time](auto comp) { comp->tick(delta_time); });
}

void GameObject::onCollision(std::shared_ptr<GameObject> &other) {
    callInAllComponents([&other](auto comp) { comp->onCollision(other); });
}

void GameObject::onTakeDamage(std::shared_ptr<class GameObject> &other, float damage_amount) {
    callInAllComponents([&other, damage_amount](auto comp) { comp->onTakeDamage(other, damage_amount); });
}

void GameObject::setPositionInc(sf::Vector2f position) {
    float delta_time = GameManager::getInstance().getDeltaTime();
    Sprite_.move(position * delta_time);
}

void GameObject::setPositionAbs(sf::Vector2f position) {
    Sprite_.setPosition(position);
}

sf::Sprite &GameObject::getSprite() { return Sprite_; }

std::string GameObject::getObjectName() { return ObjectName_; }

sf::Vector2f GameObject::getPositionAbs() { return Sprite_.getPosition(); }

void GameObject::destroy() {
    DestroyFlag_ = true;
}

bool GameObject::readyToDestroy() const {
    return DestroyFlag_;
}

GameObject::GameObject(std::string  objectName, const sf::Texture &texture, float posX, float posY,
                       [[maybe_unused]] float sizeW, [[maybe_unused]] float sizeH)
        : ObjectName_(std::move(objectName)), DestroyFlag_(false) {
    Sprite_ = sf::Sprite(texture, sf::IntRect(0, 0, static_cast<int>(sizeW), static_cast<int>(sizeH)));
    Sprite_.setPosition(posX, posY);
    Sprite_.setOrigin(sf::Vector2f(15, 0));
}

void GameObject::registerComponents() {

}

void GameObject::callInAllComponents(const std::function<void(std::shared_ptr<GameObjectComponent>)>& callback) {
    for (auto &comp: Components_) {
        callback(comp);
    }
}