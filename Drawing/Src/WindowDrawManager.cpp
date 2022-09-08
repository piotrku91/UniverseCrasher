
#include "WindowDrawManager.hpp"
#include "GameObject.hpp"

WindowDrawManager::WindowDrawManager(const std::string &Caption, int sizeW, int sizeH)
    : isDestroyed(false)
{
    WindowDrawManager_ = SDL_CreateWindow(Caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeW, sizeH, SDL_WINDOW_SHOWN);
    if (WindowDrawManager_ == NULL)
    {
        std::cout << "WindowDrawManager Error: " << SDL_GetError() << std::endl;
        throw;
    }
    renderer_ = SDL_CreateRenderer(WindowDrawManager_, -1, SDL_RENDERER_ACCELERATED);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
WindowDrawManager::~WindowDrawManager()
{
    if (!isDestroyed)
    {
        destroy();
    };
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::renderAllObjects(std::vector<std::shared_ptr<GameObject>> &allObjects)
{

    for (const auto &objectToRender : allObjects)
    {
        objectToRender->drawObject(renderer_);
    };
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::render(int posX, int posY, SDL_Texture *texture)
{
    SDL_Rect source_rect;
    source_rect.x = 0;
    source_rect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &source_rect.w, &source_rect.h);
    SDL_Rect dest_rect{posX, posY, source_rect.w, source_rect.h};
    SDL_RenderCopy(renderer_, texture, &source_rect, &dest_rect);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::render(int posX, int posY, int sizeW, int sizeH, SDL_Texture *texture, int srcShiftX, int srcShiftY)
{
    SDL_Rect source_rect{srcShiftX, srcShiftY, sizeW, sizeH};
    SDL_Rect dest_rect{posX, posY, source_rect.w, source_rect.h};
    SDL_RenderCopy(renderer_, texture, &source_rect, &dest_rect);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::render(std::shared_ptr<GameObject> &objectToRender)
{
    objectToRender->drawObject(renderer_);
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Texture *WindowDrawManager::loadTextureFromFile(const std::string &Path)
{
    SDL_Texture *texture{nullptr};
    texture = IMG_LoadTexture(renderer_, Path.c_str());
    if (!texture)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    };
    return texture;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::destroy()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(WindowDrawManager_);
    isDestroyed = true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::clear()
{
    SDL_RenderClear(renderer_);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::draw()
{
    SDL_RenderPresent(renderer_);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Renderer *WindowDrawManager::getRenderer()
{
    return renderer_;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Window *WindowDrawManager::getWindowDrawManager() const
{
    return WindowDrawManager_;
}
