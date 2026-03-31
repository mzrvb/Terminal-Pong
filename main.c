#include "pong.h"

int quit(SDL_Event event, int running)
{
    if (event.type == SDL_QUIT)
    {
        printf("quit\n");
        return running = 0;
    }

    return 1;
}

int main(int argc, char* argv[]) { // SDL2 argument for Windows compatability
    SDL_Event event; // the entire game is an event
    RenderSDL rdr;
    
    rdr.window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    rdr.surface = SDL_GetWindowSurface(rdr.window);
    rdr.color = 0xffffffff;
    rdr.clearcolor = 0x000000;
    rdr.p1 = (SDL_Rect) {40, 40, 20, 80};
    rdr.p2 = (SDL_Rect) {580, 40, 20, 80};
    rdr.ball = (SDL_Rect) {315, 235, 10, 10};
    render(rdr.surface, rdr.ball, rdr.p1, rdr.p2, rdr.color);


    int running = 1;
    while (running)
    {
        running = quit(event, running);
        // in future game.c loops, calling paddle.c and ball.c logic and stuff here

        SDL_PollEvent(&event); // check the event queue, execute the latest event
        paddleMovement(&rdr.p1, rdr.clearcolor, rdr.color, event, rdr.surface, 1);
        paddleMovement(&rdr.p2, rdr.clearcolor, rdr.color, event, rdr.surface, 2);

        SDL_UpdateWindowSurface(rdr.window);
    }
    
    SDL_Quit();
    return 0;
}