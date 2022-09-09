#pragma once

#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class TextureManagerAbs
{
public:
    virtual SDL_Texture *addTexture(const std::string &objectName, const std::string& Path) = 0;
    virtual SDL_Texture *getTexture(const std::string &objectName) = 0;
};

class TextureManager : public TextureManagerAbs
{
private:
    std::map<std::string, SDL_Texture *> List_;
    SDL_Renderer* renderer_;

public:
    void setRenderer(SDL_Renderer *renderer) { renderer_ = renderer; };

    SDL_Texture *operator[](const std::string &objectName)
    {
        return getTexture(objectName);
    }

    SDL_Texture *addTexture(const std::string &objectName, const std::string& Path) override
    {
       return List_.insert({objectName, loadTextureFromFile(Path)}).first->second;
    };

    SDL_Texture *getTexture(const std::string &objectName) override
    {
        if (List_.empty())
        {
            return nullptr;
        };
        auto it = List_.find(objectName);
        if (it != List_.end())
        {
            return it->second;
        }
        return nullptr;
    };

    void clear()
    {
        if (List_.empty())
        {
            return;
        };
        for (auto &[k, v] : List_)
        {
            SDL_DestroyTexture(v);
        }
        List_.clear();
    }

SDL_Texture* loadTextureFromFile(const std::string& Path)
{
    if (!renderer_) {return nullptr;};
    SDL_Texture *texture{nullptr};
    texture = IMG_LoadTexture(renderer_, Path.c_str());
    if (!texture)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    };
    return texture;
}

    ~TextureManager() { clear(); };
};