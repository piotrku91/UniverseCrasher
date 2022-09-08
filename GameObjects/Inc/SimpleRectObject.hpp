#pragma once
#include "GameObject.hpp"

class SimpleRectObject : public GameObject
{
protected:
    Color objectColor_;

public:
    const Color &getColor() { return objectColor_; };

    SimpleRectObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, Color &&objectColor);

    void drawObject(SDL_Renderer *renderer) override;
};
