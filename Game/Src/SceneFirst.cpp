#include "SceneFirst.hpp"
#include "Box.hpp"
#include "CreateTemplates.hpp"
#include "GameManager.hpp"
#include "Player.hpp"

void SceneFirst::tick([[maybe_unused]] float delta_time) {
}

void SceneFirst::begin() {
    sf::Texture temp;
    createGameObject<Player>(GameObjectsList_, "Player", temp, 150, 150, 50, 50, true);
    createGameObject<Box>(GameObjectsList_, "Box", temp, 500, 150, 50, 50);
}