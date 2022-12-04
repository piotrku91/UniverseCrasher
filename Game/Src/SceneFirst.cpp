#include "SceneFirst.hpp"
#include "Balloon.hpp"
#include "GameManager.hpp"
#include "Player.hpp"

void SceneFirst::tick([[maybe_unused]] float delta_time) {
    Scene::tick(delta_time);
}

void SceneFirst::begin() {
    Scene::begin();

    sf::Texture temp;
    GameManager::getInstance().createGameObject<Player>(GameObjectsList_, "Player", temp, MAX_X / 2, MAX_Y - 200, 50, 50, true);
    GameManager::getInstance().createGameObject<Balloon>(GameObjectsList_, "Balloon", temp, 500, 500, 25, 25);
    GameManager::getInstance().createGameObject<Balloon>(GameObjectsList_, "Balloon", temp, 100, 400, 25, 25);
    GameManager::getInstance().createGameObject<Balloon>(GameObjectsList_, "Balloon", temp, 600, 300, 25, 25);
    GameManager::getInstance().createGameObject<Balloon>(GameObjectsList_, "Balloon", temp, 350, 600, 25, 25);
}