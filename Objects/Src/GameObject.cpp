#include "GameObject.hpp"
#include "GameObjectComponent.hpp"
#include "GameManager.hpp"

std::shared_ptr<GameObject> GameObject::getSharedThis()
{
    return shared_from_this();
}

void GameObject::begin()
{
    callInAllComponents([this](auto comp)
                        { comp->begin(); });
};
void GameObject::tick([[maybe_unused]] float delta_time)
{
    callInAllComponents([this, delta_time](auto comp)
                        { comp->tick(delta_time); });
};

void GameObject::onCollision(std::shared_ptr<GameObject> &other)
{
    callInAllComponents([this, &other](auto comp)
                        { comp->onCollision(other); });
};
void GameObject::onTakeDamage(std::shared_ptr<class GameObject> &other, float damage_amount)
{
    callInAllComponents([this, &other, damage_amount](auto comp)
                        { comp->onTakeDamage(other, damage_amount); });
};

void GameObject::setPositionInc(sf::Vector2f position)
{
    float delta_time = GameManager::getInstance().getDeltaTime();
    Sprite_.move(position * delta_time);
};

void GameObject::setPositionAbs(sf::Vector2f position)
{
    Sprite_.setPosition(position);
};

sf::Sprite &GameObject::getSprite() { return Sprite_; };
std::string GameObject::getObjectName() { return ObjectName_; };

void GameObject::destroy()
{
    DestroyFlag_ = true;
}

bool GameObject::readyToDestroy()
{
    return DestroyFlag_;
}

GameObject::GameObject(const std::string &objectName, const sf::Texture &texture, float posX, float posY, [[maybe_unused]] float sizeX, [[maybe_unused]] float sizeY)
    : ObjectName_(objectName), DestroyFlag_(false)
{
    Sprite_ = sf::Sprite(texture, sf::IntRect(0, 0, static_cast<int>(sizeX), static_cast<int>(sizeY)));
    Sprite_.setPosition(posX, posY);
    Sprite_.setOrigin(sf::Vector2f(15, 0));
    begin();
};

void GameObject::callInAllComponents(std::function<void(std::shared_ptr<GameObjectComponent>)> callback)
{
    for (auto &comp : Components_)
    {
        callback(comp);
    };
};