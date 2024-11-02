   // Goal.cpp
   #include "Goal.h"

   Goal::Goal(float x, float y, float w, float h)
   {
       goalRect = { x, y, w, h };
   }

   void Goal::render(SDL_Renderer* renderer) const
   {
       SDL_Rect renderRect = { static_cast<int>(goalRect.x), static_cast<int>(goalRect.y), static_cast<int>(goalRect.w), static_cast<int>(goalRect.h) };
       SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red color for the goal
       SDL_RenderFillRect(renderer, &renderRect);
   }

   SDL_FRect Goal::getRect() const
   {
       return goalRect;
   }
   