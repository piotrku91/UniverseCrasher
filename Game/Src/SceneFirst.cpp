#include "SceneFirst.hpp"
#include "SimpleRectObject.hpp"

void SceneFirst::tick()
{
SDL_Delay(1000);
GameObjectsList_[0]->getObjectRect().x++;
}

void SceneFirst::begin()
{
GameObjectsList_.push_back(createObject<SimpleRectObject>({"Player 2 area", 150, 150, 50, 50, Color{0,0,100,255}}));
}