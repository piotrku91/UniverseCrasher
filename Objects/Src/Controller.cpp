#include "Controller.hpp"
#include "GameObject.hpp"
#include <functional>

void Controller::moveWithSpeed(float dX, float dY){
    if (ControlledObject_ && (dX != 0 || dY != 0))
    {
        sf::Vector2f axis{dX, dY};
        ControlledObject_->setPositionInc(axis * SpeedMultiplier_);
    }
};

void Controller::setSpeed(int speed)
{
    SpeedMultiplier_ = std::clamp(speed, 0, MaxSpeedMultiplier_);
}

void Controller::setControlledObject(std::shared_ptr<class GameObject> &object)
{
    if (!object) {return;};
    ControlledObject_ = object;
}


void Controller::resetControlledObject()
{
    ControlledObject_ = nullptr;
}