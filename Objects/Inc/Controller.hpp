#pragma once
#include <numeric>

constexpr int MaxSpeed_ = 100;

class Controller
{
private:
protected:
    bool CanMove_ = false;
    float Speed_ = 100;

public:
    virtual void move(float dX, float dY);
    void setSpeed(int speed);
};