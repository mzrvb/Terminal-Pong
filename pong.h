#include <stdio.h>
#include <SDL2/SDL.h>

// static
#define MOVEMENT_SPEED 10

typedef struct RenderSDL{
    SDL_Window *window;
    SDL_Surface *surface;
    const Uint8 *keys;
    Uint32 color;
    Uint32 clearcolor;
    SDL_Rect p1;
    SDL_Rect p2;
    SDL_Rect ball;
} RenderSDL;

typedef struct GameState{
    int score_p1;
    int score_p2;
    int running;
} GameState;

typedef struct Ball{
    int spawnx;
    int spawny;
    int velx;
    int vely;
} Ball;

// paddle.c
void paddleMovement(SDL_Rect * p1, SDL_Rect * p2, Uint32 clearcolor, Uint32 color, SDL_Surface *surface, const Uint8 *keys);

// ball.c
void resetBall(Ball *ball);
int ballMovement(SDL_Rect *ball, Uint32 clearcolor, Uint32 color, SDL_Surface *surface, SDL_Rect *p1, SDL_Rect *p2);

// game.c
int quit(SDL_Event event, int running);
void gameLogic(int scored, GameState *game, int *running);

// supposed to be render.h
void render(SDL_Surface *surface, SDL_Rect ball, SDL_Rect p1, SDL_Rect p2, Uint32 color);