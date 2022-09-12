#pragma once
#include <memory>


class Collidable
{
     
     virtual void onCollision([[maybe_unused]] std::shared_ptr<class GameObject> &other) = 0;
};