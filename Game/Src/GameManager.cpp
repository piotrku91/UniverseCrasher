#include "GameManager.hpp"
#include "WindowDrawManager.hpp"
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
            //debug(PlayerGameObject_.use_count());
            checkCollisions();
            removeDestroyedObjects();

            PlayerController_.moveWithSpeed(static_cast<float>(InputDx_), static_cast<float>(InputDy_));

            CurrentScene_->tick(getDeltaTime());

            for (auto &game_object : GameObjects_)
            {
                game_object->tick(getDeltaTime());
            }

            WindowDrawManager_.clear();
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
        ExitApp_ = !WindowDrawManager_.isOpen();
    }
    WindowDrawManager_.destroy();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                  INITS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::initMainWindow()
{
    WindowDrawManager_.create("New game", MAX_X, MAX_Y);

    Clock_.restart();
}

void GameManager::initKeyBindings()
{
    InputBindings_.insert({sf::Keyboard::Left, [this]()
                           { 
                            InputDx_--;
                            InputDx_ = std::clamp(InputDx_, -1, 0); }});

    InputBindings_.insert({sf::Keyboard::Right, [this]()
                           {
                          InputDx_++;
                            InputDx_ = std::clamp(InputDx_, 0, 1); }});
    InputBindings_.insert({sf::Keyboard::Up, [this]()
                           { 
                            InputDy_--;
                            InputDy_ = std::clamp(InputDy_, -1, 0); }});
    InputBindings_.insert({sf::Keyboard::Down, [this]()
                           { 
                            InputDy_++;
                            InputDy_ = std::clamp(InputDy_, 0, 1); }});
}

void GameManager::initTextureManager()
{
}

void GameManager::startNewGame()
{
    PlayerGameObject_ = nullptr;
    GameObjects_.clear();

    CurrentGameState_ = GameState::Play;

    CurrentScene_ = std::make_shared<SceneFirst>(GameObjects_);
    CurrentScene_->begin();

    //  RawGraphicsObjects_.push_back(createObject<SimpleRectangleObject>({"HUD Bar", {0, 0}, {MAX_X, 30}, Color{0, 100, 100, 255}}));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                  RUNTIME FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::checkCollisions()
{
    for (auto &object : GameObjects_)
    {
        for (auto &other_object : GameObjects_)
        {
            auto &object_sprite = object->getSprite();
            auto &other_object_sprite = other_object->getSprite();
            bool collision = object_sprite.getGlobalBounds().intersects(sf::FloatRect(
                other_object_sprite.getGlobalBounds().left,
                other_object_sprite.getGlobalBounds().top,
                other_object_sprite.getGlobalBounds().width,
                other_object_sprite.getGlobalBounds().height));

            if (&object != &other_object && collision)
            {
                object->onCollision(other_object);
            }
        }
    }
}

void GameManager::setPlayerGameObject(std::shared_ptr<GameObject> &player_game_object)
{
    PlayerGameObject_ = player_game_object;
    if (PlayerGameObject_)
    {
        PlayerController_.setControlledObject(PlayerGameObject_);
    }
}

std::shared_ptr<GameObject> GameManager::getPlayerGameObject()
{
    if (PlayerGameObject_)
    {
        return PlayerGameObject_;
    };
    return nullptr;
}

float GameManager::getDeltaTime()
{
    return CurrentDeltaTime_;
}

void GameManager::updateDeltaTime()
{
    CurrentDeltaTime_ = Clock_.restart().asSeconds();
}

void GameManager::removeDestroyedObjects()
{
    if (PlayerGameObject_ && PlayerGameObject_->readyToDestroy())
    {
        PlayerGameObject_ = nullptr;
        PlayerController_.resetControlledObject();
        
    };

    std::erase_if(GameObjects_,
                  [this](auto game_object)
                  {
                      return game_object->readyToDestroy();
                  });
}

void GameManager::handleEvents()
{
    sf::Event event;
    while (WindowDrawManager_.getWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            WindowDrawManager_.destroy();
        };
    };

    for (auto &key : InputBindings_)
    {

        if (sf::Keyboard::isKeyPressed(key.first))
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                  GAME EVENTS HANDLERS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::applyDamage(std::shared_ptr<GameObject>& damage_target, float damage_amount, std::shared_ptr<GameObject>& trigger_object)
{
    damage_target->onTakeDamage(trigger_object, damage_amount);
}

void GameManager::someObjectDead(std::shared_ptr<GameObject>& dead_object)
{
    if (!dead_object) {return;};

    if (dead_object == PlayerGameObject_)
    {
        dead_object->destroy();
        debug("Player dead. Game over.");
        CurrentGameState_ = GameState::Stop;
    }
    
}