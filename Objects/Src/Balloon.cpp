#include "GameObject.hpp"
#include "GameManager.hpp"
#include "Balloon.hpp"

void Balloon::begin() {
	GameObject::begin();
};

void Balloon::tick([[maybe_unused]]float delta_time)
{
	GameObject::tick(delta_time);

};

 void Balloon::onCollision([[maybe_unused]]std::shared_ptr<GameObject> &other)
{
	GameObject::onCollision(other);
	auto player_object = GameManager::getInstance().getPlayerGameObject();

	if (other == player_object)
	{
		auto self = getSharedPtr();
		GameManager::getInstance().applyDamage(player_object, 1, self);
	};
};
 void Balloon::registerComponents()
{
	Components_.push_back(std::make_shared<MoveComponent>(this, sf::Vector2f{500, 100}, 100.f));
	Components_.push_back(std::make_shared<LifeTimeComponent>(this, 30.f));
	Components_.push_back(std::make_shared<HealthComponent>(this, 50.f, 50.f));
}

Balloon::Balloon(const std::string &objectName, const sf::Texture& texture, float posX, float posY, float sizeW, float sizeH)
		: GameObject{objectName, texture, posX, posY, sizeW, sizeH} {};
