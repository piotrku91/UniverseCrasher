#include "GameManager.hpp"
#include "WindowDrawManager.hpp"
#include "SimpleRectObject.hpp"

void GameManager::runGameLoop()
{
    while (!ExitApp_)
    {
        switch (CurrentGameState_)
        {
        case GameState::MainMenu:
        {
            startNewGame();

            break;
        }
        case GameState::Play:
        {
            CurrentScene_->tick();

            WindowDrawManager_.clear();
            WindowDrawManager_.renderAllObjects(GameObjects_);

            break;
        }
        case GameState::Pause:
        {

            break;
        }
        case GameState::Stop:
        {

            break;
        }

        default:
            break;
        }

        WindowDrawManager_.draw();
    }
}

void GameManager::initMainWindow()
{
    WindowDrawManager_.create("New game", MAX_X, MAX_Y);
}

void GameManager::initTextureManager()
{
    TextureManager_.setRenderer(WindowDrawManager_.getRenderer());
}

void GameManager::startNewGame()
{
    CurrentGameState_ = GameState::Play;

    CurrentScene_ = std::make_shared<SceneFirst>(GameObjects_);
    CurrentScene_->begin();
}