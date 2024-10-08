#pragma once
#include <vector>
#include <iostream>
#include "gameObject.h"
#include "player.h"
#include "level.h"
#include "levels.h"

using std::vector;

class Game
{
private:
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const char* GAME_NAME = "OG Roguelike";
    int targetFPS = 165;
    Player* player;
    Vector2 cameraTarget = { 0 };
    Camera2D camera = { 0 };
    Level* currentLevel;

public:
    Game();
    ~Game();
    void RunGame();
    void UpdateCamera();
};