#include "pong.h"

int ballMovement(SDL_Rect *ball, Uint32 clearcolor, Uint32 color, SDL_Surface *surface, SDL_Rect *p1, SDL_Rect *p2)
{
    static int vel_x = 3;
    static int vel_y = 2;

    SDL_FillRect(surface, ball, clearcolor);

    ball->x += vel_x;
    ball->y += vel_y;

    if (ball->y < 0) vel_y = -vel_y;
    if (ball->y + ball->h > 480) vel_y = -vel_y;

    if (ball->x < 0) // p2 scored, edit spawn dir. and return 1 for gamestate
    {
        ball->x = 315;
        ball->y = 235; 
        vel_x = 3;
        vel_y = 2; 
        return 1;
    }
    if (ball->x + ball->w > 640) // p1 scored, edit spawn dir. and return 2 for gamestate
    {
        ball->x = 315;
        ball->y = 235;
        vel_x = -3;
        vel_y = 2;
        return 2;
    }

    if (SDL_HasIntersection(ball, p1)) { vel_x = -vel_x; vel_x++; }
    if (SDL_HasIntersection(ball, p2)) { vel_x = -vel_x; vel_x--; }

    SDL_FillRect(surface, ball, color);
    return 0;
}