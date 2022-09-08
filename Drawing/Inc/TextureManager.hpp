#pragma once

#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class TextureManagerAbs
{
public:
    virtual SDL_Texture *addTexture(const std::string &objectName, SDL_Texture *texture) = 0;
    virtual SDL_Texture *getTexture(const std::string &objectName) = 0;
};

class TextureManager : public TextureManagerAbs
{
private:
    std::map<std::string, SDL_Texture *> List_;

public:
    SDL_Texture *operator[](const std::string &objectName)
    {
        return getTexture(objectName);
    }

    SDL_Texture *addTexture(const std::string &objectName, SDL_Texture *texture) override
    {
        List_.insert({objectName, texture});
        return texture;
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

    ~TextureManager() { clear(); };
};