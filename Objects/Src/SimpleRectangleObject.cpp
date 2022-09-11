#include "SimpleRectangleObject.hpp"

SimpleRectangleObject::SimpleRectangleObject(const std::string &objectName, Vector2d position, Size size, Color objectColor)
    : GraphicsObject{objectName, position, size}, objectColor_{objectColor} {};

void SimpleRectangleObject::drawObject(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, getColor().getR(), getColor().getG(), getColor().getB(), getColor().getA());
    SDL_RenderFillRect(renderer, &getObjectRect());
}