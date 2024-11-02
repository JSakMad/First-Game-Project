#pragma once
#include <vector>
#include "Platform.h"
#include <SDL.h>

class Level
{
public:
    void init();
    void update();
    void render(SDL_Renderer* renderer);
    const std::vector<Platform>& getPlatforms() const;
    bool isLevelComplete() const;

private:
    std::vector<Platform> platforms;
    bool levelComplete;
};
