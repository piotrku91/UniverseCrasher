#pragma once
#include "GraphicsObject.hpp"

class SimpleRectangleObject : public GraphicsObject
{
protected:
    Color objectColor_;

public:
    const Color &getColor() { return objectColor_; };

    SimpleRectangleObject(const std::string &objectName, Vector2d position, Size size, Color objectColor);

    void drawObject(SDL_Renderer *renderer) override;
};
