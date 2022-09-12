#pragma once

#include <memory>
#include "GameStates.hpp"
#include "GameConst.hpp"
#include "WindowDrawManager.hpp"
#include "Defines.h"
#include "Debug.hpp"
#include "Controller.hpp"
#include <map>
#include <functional>

#include "SceneFirst.hpp"

class GameManager
{
private:
    GameManager() : PlayerGameObject_(nullptr), CurrentGameState_(GameState::MainMenu), ExitApp_(false){};
    WindowDrawManager WindowDrawManager_;
    GameObjectsList GameObjects_;
    GraphicsObjectsList RawGraphicsObjects_;
    std::shared_ptr<GameObject> PlayerGameObject_;
    std::shared_ptr<Scene> CurrentScene_;
    Controller PlayerController_;
    GameState CurrentGameState_;
    std::map<sf::Keyboard::Key, std::function<void()>> InputBindings_;

    bool ExitApp_;
    float CurrentDeltaTime_;
    int InputDx_;
    int InputDy_;
    sf::Clock Clock_;

public:
    static GameManager &getInstance()
    {
        static GameManager instance;
        return instance;
    };
    void initMainWindow();
    void initTextureManager();
    void initKeyBindings();
    void startNewGame();
    void runGameLoop();
    void checkCollisions();
    void removeDestroyedObjects();
    void handleEvents();
    void clearInput();

    /* Setters */
    void setPlayerGameObject(std::shared_ptr<GameObject> &player_game_object);

    /* Getters */
    std::shared_ptr<GameObject> getPlayerGameObject();
    float getDeltaTime();
    void updateDeltaTime();
};