// Game.cpp
#include "Game.h"
#include <iostream>

bool Game::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("2D Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    player.init();
    level.init();
    std::cout << "Game initialized." << std::endl;
    return true;
}

void Game::run()
{
    bool isRunning = true;
    SDL_Event e;

    while (isRunning)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                isRunning = false;
            }
            player.handleEvent(e);
        }

        processInput();
        update();
        render();
    }
    cleanup();
}

void Game::cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game cleaned up." << std::endl;
}

void Game::processInput()
{
    // Handle user input
}

void Game::update()
{
    player.update(level.getPlatforms(), deltaTime); // Pass platforms and deltaTime to the player's update method
    level.update();
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    player.render(renderer);
    level.render(renderer); // Pass the renderer to the level's render function

    SDL_RenderPresent(renderer);
}
