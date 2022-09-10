#pragma once

#include <memory>
#include "GameStates.hpp"
#include "GameConst.hpp"
#include "WindowDrawManager.hpp"
#include "TextureManager.hpp"
#include "Defines.h"
#include "Debug.hpp"

#include "SceneFirst.hpp"

class GameManager
{
private:
    GameManager() : CurrentGameState_(GameState::MainMenu), ExitApp_(false), PlayerGameObject_(nullptr), LastTick_(0){};
    WindowDrawManager WindowDrawManager_;
    TextureManager TextureManager_;
    GameObjectsList GameObjects_;
    GraphicsObjectsList RawGraphicsObjects_;
    std::shared_ptr<GameObject> PlayerGameObject_;
    std::shared_ptr<Scene> CurrentScene_;
    GameState CurrentGameState_;

    bool ExitApp_;
    uint64_t LastTick_;

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

    /* Setters */
    void setPlayerGameObject(std::shared_ptr<GameObject> &player_game_object);

    /* Getters */
    std::shared_ptr<GameObject> getPlayerGameObject();
    uint64_t getDeltaTime();
};