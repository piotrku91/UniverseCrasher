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
#include <type_traits>

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
    float getTimeFromStartS();
    void updateDeltaTime();

    /* Game events functions */
    void applyDamage(std::shared_ptr<GameObject> &damage_target, float damage_amount, std::shared_ptr<GameObject> &trigger_object);
    void someObjectDead(std::shared_ptr<GameObject> &dead_object);

    template <typename T>
    void spawnObjectAt([[maybe_unused]] T object, sf::Vector2f position, float sizeW, float sizeH)
    {
        sf::Texture temp;

        createGameObject<std::remove_pointer_t<T>>(GameObjects_, "New", temp, position.x, position.y, sizeW, sizeH);
    }

    template <typename T>
    std::shared_ptr<T> createObject(T &&args)
    {
        return std::make_shared<T>(args);
    }

    template <typename T>
    void createGameObject(GameObjectsList &game_objects_container, const std::string &objectName, const sf::Texture &texture, float posX, float posY, float sizeW, float sizeH, bool is_player = false)
    {
        std::shared_ptr<T> new_object = createObject<T>({objectName, texture, posX, posY, sizeW, sizeH});
        game_objects_container.push_back(new_object);
        new_object->registerComponents();
        new_object->begin();
        if (is_player && !GameManager::getInstance().getPlayerGameObject())
        {
            GameManager::getInstance().setPlayerGameObject(game_objects_container.back());
        };
    }
};