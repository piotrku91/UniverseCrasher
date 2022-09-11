#include "Controller.hpp"
#include <functional>

void Controller::move(int dX, int dY)
{
    updateController(dX, dY);
};

void Controller::updateController(int dX, int dY)
{
    if (dX == 0 && dY == 0)
    {
        Count_ = 1;
        CanMove_ = false;
        return;
    };

    if (Count_ == MaxSpeed_ - Speed_)
    {
        CanMove_ = true;
        Count_ = 1;
    }
    else
    {
        CanMove_ = false;
        Count_++;
    };
}

void Controller::setSpeed(int speed)
{
    Speed_ = std::clamp(speed, 0, MaxSpeed_);
}