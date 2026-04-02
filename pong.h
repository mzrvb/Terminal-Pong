#include <stdio.h>
#include <SDL2/SDL.h>

// static
#define MOVEMENT_SPEED 10

// paddle.c
void paddleMovement(SDL_Rect * p1, SDL_Rect * p2, Uint32 clearcolor, Uint32 color, SDL_Surface *surface, const Uint8 *keys);
void ballMovement(SDL_Rect *ball, Uint32 clearcolor, Uint32 color, SDL_Surface *surface, SDL_Rect *p1, SDL_Rect *p2);

// game.c
int quit(SDL_Event event, int running);

// supposed to be render.h
void render(SDL_Surface *surface, SDL_Rect ball, SDL_Rect p1, SDL_Rect p2, Uint32 color);

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