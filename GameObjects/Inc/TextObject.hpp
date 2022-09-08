#pragma once
#include "GameObject.h"

class TextObject : public GameObject
{
protected:
    Color objectColor_;
    SDL_Surface *message_;

public:
    const Color &getColor() { return objectColor_; };
    SDL_Surface *getSurface() { return message_; };

    void changeText(const std::string text, TTF_Font *font, Color &&objectColor)
    {
        free();
        message_ = TTF_RenderText_Blended(font, text.c_str(), SDL_Color{objectColor.getR(), objectColor.getG(), objectColor.getB(), objectColor.getA()});
    }

    TextObject(const std::string &objectName, int posX, int posY, int sizeW, int sizeH, const std::string text, TTF_Font *font, Color &&objectColor)
        : GameObject{objectName, posX, posY, sizeW, sizeH}, objectColor_{objectColor}
    {
        message_ = TTF_RenderText_Blended(font, text.c_str(), SDL_Color{objectColor_.getR(), objectColor_.getG(), objectColor_.getB(), objectColor_.getA()});
    };

    void drawObject(SDL_Renderer *renderer) override
    {
    }

    void free() { SDL_FreeSurface(message_); };
    ~TextObject() { free(); };
};
