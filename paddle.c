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
    if (p1->y < 0)
    {
        p1->y = 0;
    }
    if (p2->y < 0)
    {
        p2->y = 0;
    }
    if (p1->y + p1->h > 480)
    {
        p1->y = 480 - p1->h;
    }
    if (p2->y + p2->h > 480)
    {
        p2->y = 480 - p2->h;
    } 

    SDL_FillRect(surface, p1, color);
    SDL_FillRect(surface, p2, color);

}
