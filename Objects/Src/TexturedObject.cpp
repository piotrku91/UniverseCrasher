#include "TexturedObject.hpp"

// c-tors
TexturedObject::TexturedObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, SDL_Texture *texture, int sourceTextureOffsetX, int sourceTextureOffsetY)
    : GraphicsObject{objectName, posX, posY, sizeW, sizeH}, objectTexture_{texture}, sourceTextOffsetX_{sourceTextureOffsetX}, sourceTextOffsetY_{sourceTextureOffsetY} {};

// Setters
void TexturedObject::setTextureOffsetX(int sourceTextureOffsetX)
{
    sourceTextOffsetX_ = sourceTextureOffsetX;
}

void TexturedObject::setTextureOffsetY(int sourceTextureOffsetY)
{
    sourceTextOffsetY_ = sourceTextureOffsetY;
}

void TexturedObject::drawObject(SDL_Renderer *renderer) 
{
    SDL_Rect source_rect{getTextureOffsetX(), getTextureOffsetY(), getObjectRect().w, getObjectRect().h};
    getObjectRect().w = source_rect.w;
    getObjectRect().h = source_rect.h;
    SDL_RenderCopy(renderer, getObjectTexture(), &source_rect, &getObjectRect());
}