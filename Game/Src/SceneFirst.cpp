#include "SceneFirst.hpp"
#include "Player.hpp"
#include "Box.hpp"
#include "GameManager.hpp"

void SceneFirst::tick(uint32_t delta_time)
{

}

void SceneFirst::begin()
{
    sf::Texture a;
GameObjectsList_.push_back(createObject<Player>({"Player", a, 150, 150, 50, 50}));
GameManager::getInstance().setPlayerGameObject(GameObjectsList_.back());

GameObjectsList_.push_back(createObject<Box>({"Box", a, 500, 150, 50, 50}));
//GameObjectsList_.push_back(createObject<Box>({"box2", {700, 150}, {50, 50}, Color{0,0,100,255}}));
}