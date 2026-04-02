#include "pong.h"
// render p1, p2, and ball

void render(SDL_Surface *surface, SDL_Rect ball, SDL_Rect p1, SDL_Rect p2, Uint32 color)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_FillRect(surface, &p1, color);
    SDL_FillRect(surface, &p2, color);
    SDL_FillRect(surface, &ball, color);
}
