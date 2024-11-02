#include "Platform.h"

Platform::Platform(float x, float y, float w, float h)
{
    platformRect = { x, y, w, h };
}

void Platform::render(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRectF(renderer, &platformRect);
}

SDL_FRect Platform::getRect() const
{
    return platformRect;
}
