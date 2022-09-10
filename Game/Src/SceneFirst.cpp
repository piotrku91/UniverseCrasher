#include "SceneFirst.hpp"
#include "GameObject.hpp"
#include "GameManager.hpp"

void SceneFirst::tick(uint32_t delta_time)
{
GameObjectsList_[0]->getObjectRect().x += 1 * delta_time;
}
void SceneFirst::begin()
{
GameObjectsList_.push_back(createObject<GameObject>({"Player", 150, 150, 50, 50, Color{0,0,100,255}}));
GameManager::getInstance().setPlayerGameObject(GameObjectsList_.back());

GameObjectsList_.push_back(createObject<GameObject>({"box", 500, 150, 50, 50, Color{0,0,100,255}}));

GameObjectsList_.push_back(createObject<GameObject>({"box2", 700, 150, 50, 50, Color{0,0,100,255}}));
}