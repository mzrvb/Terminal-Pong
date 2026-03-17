#include <stdio.h>
#include <SDL2/SDL.h>
#define BALL_SPEED 20

typedef struct {
    int x, y;
} Ball;

typedef struct {
    int top_y, bot_y;
} Paddle;