#include "pong.h"

void ballMovement(SDL_Rect *ball, Uint32 clearcolor, Uint32 color, SDL_Surface *surface, SDL_Rect *p1, SDL_Rect *p2)
{
    static int vel_x = 3;
    static int vel_y = 2;

    SDL_FillRect(surface, ball, clearcolor);

    ball->x += vel_x;
    ball->y += vel_y;

    // top and bottom wall bounce
    if (ball->y < 0) // top 
    {
        vel_y = -vel_y;
    }
    if (ball->y + ball->h > 480) // bottom
    {
        vel_y = -vel_y;
    }

    // left and right wall bounce (reset later)
    if (ball->x < 0 || ball->x + ball->w > 640) vel_x = -vel_x;

    // paddle collision
    if (SDL_HasIntersection(ball, p1))
    {
        vel_x = -vel_x;
        vel_x++;
        printf("%d\n", vel_x);
    }
    if (SDL_HasIntersection(ball, p2))
    {
        vel_x = -vel_x;
        vel_x--;
        printf("%d\n", vel_x);
    }

    SDL_FillRect(surface, ball, color);
}