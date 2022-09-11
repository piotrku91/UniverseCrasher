
#include "WindowDrawManager.hpp"
#include "Maths.hpp"

WindowDrawManager::WindowDrawManager()
    : isDestroyed(false), Created_(false)
{
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
void WindowDrawManager::render(Vector2d position, Size size, SDL_Texture *texture, int srcShiftX, int srcShiftY)
{
    SDL_Rect source_rect{srcShiftX, srcShiftY, size.width, size.height};
    SDL_Rect dest_rect{position.getX(), position.getY(), source_rect.w, source_rect.h};
    SDL_RenderCopy(renderer_, texture, &source_rect, &dest_rect);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::create(const std::string &Caption, int sizeW, int sizeH)
{
SDLWindow_ = SDL_CreateWindow(Caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeW, sizeH, SDL_WINDOW_SHOWN);
    if (SDLWindow_ == NULL)
    {
        std::cout << "WindowDrawManager Error: " << SDL_GetError() << std::endl;
        throw;
    }
    renderer_ = SDL_CreateRenderer(SDLWindow_, -1, SDL_RENDERER_ACCELERATED);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowDrawManager::destroy()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(SDLWindow_);
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
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0); // To do: make setter of window background color.
    SDL_RenderPresent(renderer_);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Renderer *WindowDrawManager::getRenderer()
{
    return renderer_;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Window *WindowDrawManager::getSDLWindow() const
{
    return SDLWindow_;
}
