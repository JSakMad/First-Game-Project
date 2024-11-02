   // Goal.h
   #ifndef GOAL_H
   #define GOAL_H

   #include "SDL.h"

   class Goal
   {
   public:
       Goal(float x, float y, float w, float h);
       void render(SDL_Renderer* renderer) const;
       SDL_FRect getRect() const;

   private:
       SDL_FRect goalRect;
   };

   #endif // GOAL_H
   