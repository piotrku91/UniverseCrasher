#include <memory>
#include <vector>
#include <iostream>

// Graphics layer libs
#include "WindowDrawManager.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "SimpleRectObject.hpp"
#include "Color.hpp"

constexpr auto MAX_X=800;
constexpr auto MAX_Y=600; 
constexpr auto PLAYERS_AREA_W=500; 
constexpr auto PLAYERS_AREA_H=150; 
constexpr auto BIGCARD_AREA_W=220; 
constexpr auto BIGCARD_AREA_H=270; 


int main() {
std::vector<std::shared_ptr<GameObject>> Objects;
// Load main WindowDrawManager
WindowDrawManager mainWindowDrawManager{"New game", MAX_X, MAX_Y};

 //Init texture manager and load textures
TextureManager TextureMgr;
//TextureMgr.addTexture("first",mainWindowDrawManager.loadTextureFromFile("textures/jeden.jpg"));

 //Create textured objects
//Objects.push_back(std::make_shared<TexturedObject>(TexturedObject{"texturowy 1",32,32,128,128,TextureMgr["first"]}));//

// Players area
Objects.push_back(createObject<SimpleRectObject>({"Player 2 area", MAX_X - PLAYERS_AREA_W, 0, PLAYERS_AREA_W, PLAYERS_AREA_H, Color{0,0,100,255}}));

// Render section
mainWindowDrawManager.clear();
mainWindowDrawManager.renderAllObjects(Objects);

mainWindowDrawManager.draw();


SDL_Delay(2000);

// Cleaning
mainWindowDrawManager.destroy();
    return 0;
}