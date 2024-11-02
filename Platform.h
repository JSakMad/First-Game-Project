// Platform.h
#pragma once
#include <SDL.h>

class Platform
{
public:
    Platform(float x, float y, float w, float h);

    void render(SDL_Renderer* renderer) const;

    SDL_FRect getRect() const;

private:
    SDL_FRect platformRect;
};
