#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class GameObject;

class WindowDrawManager final {
private:
    SDL_Window* WindowDrawManager_;
    SDL_Renderer* renderer_;
    bool isDestroyed;

public:
    WindowDrawManager(const std::string& Caption, int sizeW, int sizeH);
    ~WindowDrawManager();

    void render(int posX, int posY, SDL_Texture* texture);
    void render(int posX, int posY, int sizeW, int sizeH, SDL_Texture* texture, int srcShiftX = 0, int srcShiftY = 0);
    void render(std::shared_ptr<GameObject>& objectToRender);
    void renderAllObjects(std::vector<std::shared_ptr<GameObject>>& allObjects);

    SDL_Texture* loadTextureFromFile(const std::string& Path);

    void destroy();
    void clear();
    void draw();

    SDL_Renderer* getRenderer();
    SDL_Window* getWindowDrawManager() const;
};