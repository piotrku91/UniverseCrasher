#include "SimpleRectangleObject.hpp"

SimpleRectangleObject::SimpleRectangleObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, Color objectColor)
    : GraphicsObject{objectName, posX, posY, sizeW, sizeH}, objectColor_{objectColor} {};

void SimpleRectangleObject::drawObject(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, getColor().getR(), getColor().getG(), getColor().getB(), getColor().getA());
    SDL_RenderFillRect(renderer, &getObjectRect());
}