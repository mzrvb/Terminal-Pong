#include "pong.h"

void paddleMovement(SDL_Rect * player, Uint32 clearcolor, Uint32 color, SDL_Event event, SDL_Surface *surface, Uint8 *keys, int playerbtn)
{
    SDL_FillRect(surface, player, clearcolor); // clear previous position

    if (playerbtn == 1)
    {
        if (keys[SDL_SCANCODE_UP]) 
        {
            player->y -= MOVEMENT_SPEED;
        }
        if (keys[SDL_SCANCODE_DOWN]) 
        {
            player->y += MOVEMENT_SPEED;
        }
    }
    if (playerbtn == 2)
    {
        if (keys[SDL_SCANCODE_H]) 
        {
            player->y -= MOVEMENT_SPEED;
        }
        if (keys[SDL_SCANCODE_N]) 
        {
            player->y += MOVEMENT_SPEED;
        }
    }

    SDL_FillRect(surface, player, color);
}
