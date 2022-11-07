#include "SceneFirst.hpp"
#include "Box.hpp"
#include "CreateTemplates.hpp"
#include "GameManager.hpp"
#include "Player.hpp"

void SceneFirst::tick([[maybe_unused]] float delta_time) {
    Scene::tick(delta_time);
}

void SceneFirst::begin() {
    Scene::begin();

    sf::Texture temp;
    createGameObject<Player>(GameObjectsList_, "Player", temp, MAX_X / 2, MAX_Y - 200, 50, 50, true);
    createGameObject<Box>(GameObjectsList_, "Box", temp, 500, 500, 25, 25);
}