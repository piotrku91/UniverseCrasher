#pragma once

#include "GraphicsObject.hpp"

class TexturedObject : public GraphicsObject
{
private:
    SDL_Texture *objectTexture_;
    int sourceTextOffsetX_;
    int sourceTextOffsetY_;

public:
    // c-tors
    TexturedObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, SDL_Texture *texture, int sourceTextureOffsetX = 0, int sourceTextureOffsetY = 0);
    // Setters
    void setTextureOffsetX(int sourceTextureOffsetX);
    void setTextureOffsetY(int sourceTextureOffsetY);

    void drawObject(SDL_Renderer *renderer) override;

    // Getters
    SDL_Texture *getObjectTexture() { return objectTexture_; };
    int getTextureOffsetX() { return sourceTextOffsetX_; };
    int getTextureOffsetY() { return sourceTextOffsetY_; };
};