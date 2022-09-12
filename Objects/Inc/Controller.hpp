#pragma once
#include <numeric>
#include <memory>

constexpr int MaxSpeedMultiplier_ = 100;

class Controller
{
private:
std::shared_ptr<class GameObject> ControlledObject_;

protected:
    float SpeedMultiplier_ = 100;

public:
    virtual void moveWithSpeed(float dX, float dY);
    void setSpeed(int speed);

    void setControlledObject(std::shared_ptr<class GameObject>& object);
    void resetControlledObject();
};