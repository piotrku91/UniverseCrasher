#pragma once
#include "stdint.h"

class Color
{
protected:
    uint8_t R_;
    uint8_t G_;
    uint8_t B_;
    uint8_t A_;

public:
    uint8_t getR() const { return R_; };
    uint8_t getG() const { return G_; };
    uint8_t getB() const { return B_; };
    uint8_t getA() const { return A_; };

     Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
        : R_{R}, G_{G}, B_{B}, A_{A} {};


};