#pragma once
#include <numeric>

constexpr int MaxSpeed_ = 100;

class Controller
{
private:
    int Speed_ = 20;
    int Count_ = 0;

protected:
    bool CanMove_ = false;

public:
    virtual void move(int dX, int dY);
    void updateController(int dX, int dY);
    void setSpeed(int speed);
};