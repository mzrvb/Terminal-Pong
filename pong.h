#include <stdio.h>
#include <SDL2/SDL.h>

// static
#define MOVEMENT_SPEED 10

// paddle.c
void paddleMovement(SDL_Rect * player, Uint32 clearcolor, Uint32 color, SDL_Event event, SDL_Surface *surface, Uint8 *keys, int playerbtn);

// supposed to be render.h
void render(SDL_Surface *surface, SDL_Rect ball, SDL_Rect p1, SDL_Rect p2, Uint32 color);
typedef struct RenderSDL{
    SDL_Window *window;
    SDL_Surface *surface;
    Uint32 color;
    Uint32 clearcolor;
    Uint8 *keys;
    SDL_Rect p1;
    SDL_Rect p2;
    SDL_Rect ball;
} RenderSDL;