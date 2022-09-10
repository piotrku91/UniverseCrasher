#include <memory>
#include <vector>
#include <iostream>

// Graphics layer libs

/* #include "TextureManager.hpp"
#include "GameObject.hpp"
#include "SimpleRectangleObject.hpp"
#include "Color.hpp" */
#include "GameManager.hpp"

/* constexpr auto PLAYERS_AREA_W=500; 
constexpr auto PLAYERS_AREA_H=150; 
constexpr auto BIGCARD_AREA_W=220; 
constexpr auto BIGCARD_AREA_H=270;  */


int main() {
GameManager& Game = GameManager::getInstance();
Game.initMainWindow();
Game.initTextureManager();
Game.runGameLoop();


 //Init texture manager and load textures
//TextureMgr.addTexture("first",mainWindowDrawManager.loadTextureFromFile("textures/jeden.jpg"));

 //Create textured objects
//Objects.push_back(std::make_shared<TexturedObject>(TexturedObject{"texturowy 1",32,32,128,128,TextureMgr["first"]}));//

SDL_Delay(2000);

// Cleaning
//mainWindowDrawManager.destroy(); 
    return 0;
}