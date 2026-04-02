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

    // collision logic, reflect, 
    if (SDL_HasIntersection(ball, p1))
    {
        vel_x = -vel_x;
        vel_x++;
        int offset = (ball->y + ball->h / 2) - (p1->y + p1->h / 2);
        vel_y = offset / 16;
    }
    if (SDL_HasIntersection(ball, p2))
    {
        vel_x = -vel_x;
        vel_x--;
        int offset = (ball->y + ball->h / 2) - (p2->y + p2->h / 2);
        vel_y = offset / 16;
    }

    SDL_FillRect(surface, ball, color);
    return 0;
}