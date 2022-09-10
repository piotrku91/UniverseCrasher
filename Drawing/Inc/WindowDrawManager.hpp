#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class GameObject;

class WindowDrawManager final
{
private:
    SDL_Window *SDLWindow_;
    SDL_Renderer *renderer_;
    bool isDestroyed;
    bool Created_;

public:
    WindowDrawManager();
    ~WindowDrawManager();

    void render(int posX, int posY, SDL_Texture *texture);
    void render(int posX, int posY, int sizeW, int sizeH, SDL_Texture *texture, int srcShiftX = 0, int srcShiftY = 0);

    /* Template functions */
    template <typename T>
    void render(std::shared_ptr<T> &objectToRender)
    {
        objectToRender->drawObject(renderer_);
    }

    template <typename T>
    void renderAllObjects(std::vector<std::shared_ptr<T>> &allObjects)
    {

        for (const auto &objectToRender : allObjects)
        {
            objectToRender->drawObject(renderer_);
        };
    }

    void create(const std::string &Caption, int sizeW, int sizeH);
    void destroy();
    void clear();
    void draw();

    SDL_Renderer *getRenderer();
    SDL_Window *getSDLWindow() const;
};