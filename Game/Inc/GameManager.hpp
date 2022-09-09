#pragma once

#include <memory>
#include "GameStates.hpp"
#include "GameConst.hpp"
#include "WindowDrawManager.hpp"
#include "TextureManager.hpp"
#include "Defines.h"

#include "SceneFirst.hpp"

class GameManager
{
private:
    GameManager() : CurrentGameState_(GameState::MainMenu), ExitApp_(false){};
    GameState CurrentGameState_;
    WindowDrawManager WindowDrawManager_;
    GameObjectsList GameObjects_;
    TextureManager TextureManager_;
    std::shared_ptr<Scene> CurrentScene_;
    bool ExitApp_;

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
};