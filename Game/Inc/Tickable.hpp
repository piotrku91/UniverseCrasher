#pragma once

class Tickable
{
    public:
    virtual void begin() = 0;
    virtual void tick(float delta_time) = 0;
};