#pragma once

#include <string>
#include <memory>
#include "Color.hpp"
#include "Tickable.hpp"
#include "Debug.hpp"
#include "SFML/Graphics.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
class GameObject : public Tickable
{
private:
    std::string ObjectName_;

    bool DestroyFlag_;

protected:
    sf::Sprite Sprite_;

public:
    virtual void begin() override{};
    virtual void tick(uint32_t delta_time) override{};
    sf::Sprite &getSprite() { return Sprite_; };
    std::string getObjectName() { return ObjectName_; };

    virtual void onCollision(std::shared_ptr<GameObject> &other){};

    void destroy()
    {
        DestroyFlag_ = true;
    }

    bool readyToDestroy()
    {
        return DestroyFlag_;
    }

    GameObject(const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeX, float sizeY)
        : ObjectName_(objectName), DestroyFlag_(false)
    {
        Sprite_ = sf::Sprite(texture, sf::IntRect(0, 0, sizeX, sizeY));
        Sprite_.setPosition(posX, posY);
        Sprite_.setOrigin(sf::Vector2f(15, 0));
        begin();
    };
};