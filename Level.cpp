#include "Level.h"

void Level::init()
{
    levelComplete = false;

    // Initialize platforms here
    float platformWidth = 200.0f;
    float platformHeight = 20.0f;

    // Add platforms at different heights
    platforms.emplace_back(300.0f, 500.0f, platformWidth, platformHeight);
    platforms.emplace_back(100.0f, 400.0f, platformWidth, platformHeight);
    platforms.emplace_back(500.0f, 300.0f, platformWidth, platformHeight);
    platforms.emplace_back(200.0f, 200.0f, platformWidth, platformHeight);

    // Add the goal platform at the bottom
    float goalPlatformWidth = 200.0f;
    float goalPlatformHeight = 20.0f;
    float goalPlatformX = (800.0f - goalPlatformWidth) / 2.0f; // Center horizontally
    float goalPlatformY = 600.0f - goalPlatformHeight - 10.0f; // Near bottom with a 10-pixel margin

    platforms.emplace_back(goalPlatformX, goalPlatformY, goalPlatformWidth, goalPlatformHeight);
}

void Level::update()
{
    // Update platforms here
}

void Level::render(SDL_Renderer* renderer)
{
    // Render platforms here
    for (const auto& platform : platforms)
    {
        platform.render(renderer);
    }
}

const std::vector<Platform>& Level::getPlatforms() const
{
    return platforms; // Return the platforms
}

bool Level::isLevelComplete() const
{
    return levelComplete;
}
