#include "pong.h"

void paddleMovement(SDL_Rect * p1, SDL_Rect * p2, Uint32 clearcolor, Uint32 color, SDL_Surface *surface, const Uint8 *keys)
{
    SDL_FillRect(surface, p1, clearcolor); // clear previous position
    SDL_FillRect(surface, p2, clearcolor); // clear previous position

    if (keys[SDL_SCANCODE_UP]) 
    {
        p1->y -= MOVEMENT_SPEED;
    }
    if (keys[SDL_SCANCODE_DOWN]) 
    {
        p1->y += MOVEMENT_SPEED;
    }
    if (keys[SDL_SCANCODE_H]) 
    {
        p2->y -= MOVEMENT_SPEED;
    }
    if (keys[SDL_SCANCODE_N]) 
    {
        p2->y += MOVEMENT_SPEED;
    }

    SDL_FillRect(surface, p1, color);
    SDL_FillRect(surface, p2, color);

}
