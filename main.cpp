// main.cpp
#include "SDL.h"
#include "Player.h"
#include "Platform.h"
#include "Goal.h"
#include <vector>

int main(int argc, char* args[])
{
    // Initialize SDL and create window, renderer, etc.

    Player player;
    player.init();

    std::vector<Platform> platforms;
    // Add platforms to the vector

    Goal goal(750.0f, 550.0f, 50.0f, 50.0f); // Example goal position and size

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            player.handleEvent(e);
        }

        player.update(platforms, goal);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Render platforms
        for (const auto& platform : platforms)
        {
            platform.render(renderer);
        }

        // Render goal
        goal.render(renderer);

        // Render player
        player.render(renderer);

        // Update screen
        SDL_RenderPresent(renderer);

        if (player.isLevelComplete())
        {
            std::cout << "Level Complete!" << std::endl;
            quit = true; // For simplicity, quit the game when the level is complete
        }
    }

    // Clean up and quit SDL
    return 0;
}
