#pragma once

class Tickable
{
    public:
    virtual void begin() = 0;
    virtual void tick(uint32_t delta_time) = 0;
};