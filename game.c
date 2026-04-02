#include "pong.h"

int quit(SDL_Event event, int running)
{
    if (event.type == SDL_QUIT) return running = 0;
    return 1;
}