#include "SimpleRectObject.hpp"

SimpleRectObject::SimpleRectObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, Color &&objectColor)
    : GameObject{objectName, posX, posY, sizeW, sizeH}, objectColor_{objectColor} {};

void SimpleRectObject::drawObject(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, getColor().getR(), getColor().getG(), getColor().getB(), getColor().getA());
    SDL_RenderFillRect(renderer, &getObjectRect());
}