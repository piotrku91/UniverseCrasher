#pragma once

#include <functional>
#include <map>
#include <memory>
#include "Controller.hpp"
#include "Debug.hpp"
#include "Defines.h"
#include "GameConst.hpp"
#include "GameStates.hpp"
#include "SceneFirst.hpp"
#include "WindowDrawManager.hpp"

class GameManager
{
private:
    GameManager()
        : PlayerGameObject_(nullptr), CurrentGameState_(GameState::MainMenu), ExitApp_(false){};
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
    int InputFire_;
    sf::Clock DeltaClock_;
    sf::Clock GlobalClock_;

public:
    static GameManager &getInstance()
    {
        static GameManager instance;
        return instance;
    };
    /* Inits */
    void initMainWindow();
    void initTextureManager();
    void initKeyBindings();

    /* Runtime control */
    void startNewGame();
    void runGameLoop();

    /* Game runtime functions */
    void checkCollisions();
    void removeDestroyedObjects();
    void handleEvents();
    void clearInput();

    /* Setters */
    void setPlayerGameObject(std::shared_ptr<GameObject> &player_game_object);

    /* Getters */
    std::shared_ptr<GameObject> getPlayerGameObject();
    float getDeltaTime();
    float getTimeFromStart();
    void updateDeltaTime();

    /* Game events functions */
    void applyDamage(std::shared_ptr<GameObject> &damage_target, float damage_amount, std::shared_ptr<GameObject> &trigger_object);
    void someObjectDead(std::shared_ptr<GameObject> &dead_object);

    template <typename T>
    void spawnObjectAt([[maybe_unused]]T &object, sf::Vector2f position)
    {
        sf::Texture temp;
       // createGameObject<Box>(GameObjects_, "New", temp, position.x, position.y, 25, 25);
    }
};