#pragma once

#include <memory>
#include "GameStates.hpp"
#include "GameConst.hpp"
#include "WindowDrawManager.hpp"
#include "Defines.h"
#include "Debug.hpp"
#include <map>
#include <functional>

#include "SceneFirst.hpp"

class GameManager
{
private:
    GameManager() : PlayerGameObject_(nullptr), CurrentGameState_(GameState::MainMenu), ExitApp_(false), LastTick_(0){};
    WindowDrawManager WindowDrawManager_;
    GameObjectsList GameObjects_;
    GraphicsObjectsList RawGraphicsObjects_;
    std::shared_ptr<GameObject> PlayerGameObject_;
    std::shared_ptr<Scene> CurrentScene_;
    GameState CurrentGameState_;
    std::map<uint8_t, std::function<void()>> InputBindings_;

    bool ExitApp_;
    uint64_t LastTick_;
    uint32_t CurrentDeltaTime_;
    int InputDx_;
    int InputDy_;

public:
    static GameManager &getInstance()
    {
        static GameManager instance;
        return instance;
    };
    void initMainWindow();
    void initTextureManager();
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
    uint32_t getDeltaTime();
    void updateDeltaTime();
};