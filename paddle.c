#include "pong.h"

void paddleMovement(SDL_Rect * player, Uint32 clearcolor, Uint32 color, SDL_Event event, SDL_Surface *surface, int playerbtn)
{
    if (event.type == SDL_KEYDOWN)
    {
        int keypressed = event.key.keysym.scancode; // use scancode for physical key location
        SDL_FillRect(surface, player, clearcolor); // clear previous rectangle position

        if (playerbtn == 1) // player one controls
        {
            if (keypressed == SDL_SCANCODE_DOWN)
            {
                player->y+= MOVEMENT_SPEED;
            }
            else if (keypressed == SDL_SCANCODE_UP)
            {
                player->y-= MOVEMENT_SPEED;
            }
        }
        else if (playerbtn == 2) // player two controls
        {
            if (keypressed == SDL_SCANCODE_N)
            {
                player->y+= MOVEMENT_SPEED;
            }
            else if (keypressed == SDL_SCANCODE_H)
            {
                player->y-= MOVEMENT_SPEED;
            }
        }
        
        SDL_FillRect(surface, player, color); // update p1 movement
    } 
}
