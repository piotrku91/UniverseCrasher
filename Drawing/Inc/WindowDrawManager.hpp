#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Maths.hpp"
#include "SFML/Graphics.hpp"

class GameObject;

class WindowDrawManager final
{
private:
    bool isDestroyed;
    bool Created_;
    sf::RenderWindow Window;

public:
    WindowDrawManager();
    ~WindowDrawManager();

    template <typename T>
    void renderAllObjects(std::vector<std::shared_ptr<T>> &allObjects)
    {

        for (const auto &objectToRender : allObjects)
        {
            objectToRender->drawObject();
        };
    }

    void create(const std::string &Caption, int sizeW, int sizeH);
    void destroy();
    void clear();
    void draw();
    sf::RenderWindow& getWindow() {return Window;};
    inline bool isOpen() {return Window.isOpen();};
};