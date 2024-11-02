// Game.h
#pragma once
#include "Player.h"
#include "Level.h"
#include <SDL.h>

class Game
{
public:
    Game() : player(), level(), window(nullptr), renderer(nullptr) {} // Constructor with initializer list

    bool init();
    void run();
    void cleanup();

private:
    void processInput();
    void update();
    void render();

    Player player;
    Level level;
    SDL_Window* window;
    SDL_Renderer* renderer;
};