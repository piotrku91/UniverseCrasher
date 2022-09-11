#include "TexturedObject.hpp"

// c-tors
TexturedObject::TexturedObject(const std::string &objectName, Vector2d position, Size size, SDL_Texture *texture, int sourceTextureOffsetX, int sourceTextureOffsetY)
    : GraphicsObject{objectName, position, size}, objectTexture_{texture}, sourceTextOffsetX_{sourceTextureOffsetX}, sourceTextOffsetY_{sourceTextureOffsetY} {};

// Setters
void TexturedObject::setTextureOffsetX(int sourceTextureOffsetX)
{
    sourceTextOffsetX_ = sourceTextureOffsetX;
}

void TexturedObject::setTextureOffsetY(int sourceTextureOffsetY)
{
    sourceTextOffsetY_ = sourceTextureOffsetY;
}

void TexturedObject::drawObject() 
{

}
