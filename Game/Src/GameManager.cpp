#include "GameManager.hpp"
#include "WindowDrawManager.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"
#include "Controller.hpp"
#include <algorithm>
#include <numeric>

void GameManager::runGameLoop()
{
    while (!ExitApp_)
    {
        updateDeltaTime();
        handleEvents();

        switch (CurrentGameState_)
        {
        case GameState::MainMenu:
        {
            startNewGame();

            break;
        }
        case GameState::Play:
        {
            Controller *player_controller = dynamic_cast<Controller *>(PlayerGameObject_.get());

            checkCollisions();
            removeDestroyedObjects();

            player_controller->move(InputDx_, InputDy_);

            CurrentScene_->tick(getDeltaTime());

            for (auto &game_object : GameObjects_)
            {
                game_object->tick(getDeltaTime());
            }

            WindowDrawManager_.clear();
            WindowDrawManager_.renderAllObjects(RawGraphicsObjects_);
            WindowDrawManager_.renderAllObjects(GameObjects_);

            clearInput();

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
    WindowDrawManager_.destroy();
}

void GameManager::initMainWindow()
{
    WindowDrawManager_.create("New game", MAX_X, MAX_Y);

    InputBindings_.insert({SDL_SCANCODE_LEFT, [this]()
                           { 
                            InputDx_--;
                            InputDx_ = std::clamp(InputDx_, -1, 0); }});

    InputBindings_.insert({SDL_SCANCODE_RIGHT, [this]()
                           {
                          InputDx_++;
                            InputDx_ = std::clamp(InputDx_, 0, 1); }});
    InputBindings_.insert({SDL_SCANCODE_UP, [this]()
                           { 
                            InputDy_--;
                            InputDy_ = std::clamp(InputDy_, -1, 10); }});
    InputBindings_.insert({SDL_SCANCODE_DOWN, [this]()
                           { 
                            InputDy_++;
                            InputDy_ = std::clamp(InputDy_, 0, 1); }});
}

void GameManager::initTextureManager()
{
    TextureManager_.setRenderer(WindowDrawManager_.getRenderer());
}

void GameManager::startNewGame()
{
    PlayerGameObject_ = nullptr;
    GameObjects_.clear();

    CurrentGameState_ = GameState::Play;

    CurrentScene_ = std::make_shared<SceneFirst>(GameObjects_);
    CurrentScene_->begin();

    RawGraphicsObjects_.push_back(createObject<SimpleRectangleObject>({"HUD Bar", {0, 0}, {MAX_X, 30}, Color{0, 100, 100, 255}}));
}

void GameManager::checkCollisions()
{
    for (auto &object : GameObjects_)
    {
        for (auto &other_object : GameObjects_)
        {
            if (&object != &other_object && SDL_HasIntersection(&object->getObjectRect(), &other_object->getObjectRect()) != SDL_FALSE)
            {
                object->onCollision(other_object);
                other_object->onCollision(object);
            }
        }
    }
}

void GameManager::setPlayerGameObject(std::shared_ptr<GameObject> &player_game_object)
{
    PlayerGameObject_ = player_game_object;
}

std::shared_ptr<GameObject> GameManager::getPlayerGameObject()
{
    if (PlayerGameObject_)
    {
        return PlayerGameObject_;
    };
    return nullptr;
}

uint32_t GameManager::getDeltaTime()
{
    return CurrentDeltaTime_;
}

void GameManager::updateDeltaTime()
{
    uint64_t tick_time = SDL_GetTicks64();
    CurrentDeltaTime_ = static_cast<uint32_t>(tick_time - LastTick_);
    if (CurrentDeltaTime_ == 0)
    {
        CurrentDeltaTime_ = 1;
    };
    LastTick_ = tick_time;
}

void GameManager::removeDestroyedObjects()
{
    if (PlayerGameObject_->readyToDestroy())
    {
        PlayerGameObject_ = nullptr;
    };

    std::erase_if(GameObjects_,
                  [this](auto game_object)
                  {
                      return game_object->readyToDestroy();
                  });
}

void GameManager::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_WINDOWEVENT:
        {

            if (event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                ExitApp_ = true;
                break;
            }
            break;
        }

        default:
            break;
        };
    }

    int num = 0;
    const Uint8 *keyboard = SDL_GetKeyboardState(&num);
    for (auto &key : InputBindings_)
    {

        if (keyboard[key.first])
        {
            key.second();
        }
    };
}

void GameManager::clearInput()
{
    InputDx_ = 0;
    InputDy_ = 0;
}