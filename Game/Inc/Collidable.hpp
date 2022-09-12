#pragma once
#include <memory>


class Collidable
{
     
     virtual void onCollision(std::shared_ptr<class GameObject> &other) = 0;
};