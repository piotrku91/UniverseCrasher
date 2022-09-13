#pragma once
#include "GameManager.hpp"

template <typename T>
std::shared_ptr<T> createObject(T&& args) {
    return std::make_shared<T>(args);
}

template <typename T>
void createGameObject(GameObjectsList& game_objects_container, const std::string& objectName, const sf::Texture& texture, float posX, float posY, [[maybe_unused]] float sizeW, [[maybe_unused]] float sizeH, bool is_player = false) {
    std::shared_ptr<T> new_object = createObject<T>({objectName, texture, posX, posY, sizeW, sizeH});
    game_objects_container.push_back(new_object);
    new_object->registerComponents();
    new_object->begin();
    if (is_player && !GameManager::getInstance().getPlayerGameObject()) {
        GameManager::getInstance().setPlayerGameObject(game_objects_container.back());
    };
}