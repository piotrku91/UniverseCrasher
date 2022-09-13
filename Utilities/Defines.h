#pragma once
#include <vector>
#include <memory>

using GameObjectsList = std::vector<std::shared_ptr<class GameObject>> ;
using GameObjectsComponentsList = std::vector<std::shared_ptr<class GameObjectComponent>> ;
using GraphicsObjectsList = std::vector<std::shared_ptr<class GraphicsObject>> ;


