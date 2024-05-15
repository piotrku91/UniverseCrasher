#pragma once
#include "GameObject.hpp"
#include "Debug.hpp"

class Player : public GameObject
{

public:
    virtual void begin() override;
    virtual void tick([[maybe_unused]] float delta_time) override;
    virtual void onCollision(std::shared_ptr<class GameObject> &other) override;
    virtual void registerComponents();

    void Fire();

    Player(const std::string &objectName, const sf::Texture& texture, float posX, float posY, float sizeW, float sizeH);
};