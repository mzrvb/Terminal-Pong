#include "pong.h"

int quit(SDL_Event event, int running)
{
    if (event.type == SDL_QUIT) return running = 0;
    return 1;
}

void gameLogic(int scored, GameState *game, int *running)
{
    // increment scores
    if (scored == 1)
    {  
        printf("p1 scored!\n");
        game->score_p1++;
        SDL_Delay(500);
    }
    if (scored == 2)
    {
        printf("p2 scored!\n");
        game->score_p2++;
        SDL_Delay(500);
    }

    // win condition
    if (game->score_p1 >= 2)
    {
        printf("p1 wins!\n");
        *running = 0;
        SDL_Delay(500);
    }
    if (game->score_p2 >= 2)
    {
        printf("p2 wins!\n");
        *running = 0;
        SDL_Delay(500);
    }
}
