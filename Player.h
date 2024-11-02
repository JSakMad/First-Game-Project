// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"
#include "Platform.h"

class Player
{
public:
    void init();
    void update(const std::vector<Platform>& platforms, const Goal& goal); // Updated method signature
    void render(SDL_Renderer* renderer);
    void handleEvent(SDL_Event& e);
    void checkCollision(const std::vector<Platform>& platforms, const Goal& goal);

    bool isLevelComplete() const { return levelComplete; }

private:
    SDL_FRect playerRect;
    float velX, velY;
    bool isJumping;
    bool leftPressed, rightPressed;
    bool levelComplete;
};
