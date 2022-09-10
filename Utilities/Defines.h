#pragma once
#include <vector>
#include <memory>

using GameObjectsList = std::vector<std::shared_ptr<class GameObject>> ;
using GraphicsObjectsList = std::vector<std::shared_ptr<class GraphicsObject>> ;

template <typename T>
std::shared_ptr<T> createObject(T&& args)
{
    return std::make_shared<T>(args);
}
