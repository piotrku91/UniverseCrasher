#include "Controller.hpp"
#include <functional>

void Controller::move(float dX, float dY)
{
};

void Controller::setSpeed(int speed)
{
    Speed_ = std::clamp(speed, 0, MaxSpeed_);
}