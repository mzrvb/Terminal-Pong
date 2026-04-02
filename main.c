#include "pong.h"

int main(int argc, char* argv[]) { // SDL2 argument for Windows compatability
    SDL_Event event;
    RenderSDL rdr;
    
    // render struct values
    rdr.window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    rdr.surface = SDL_GetWindowSurface(rdr.window);
    rdr.keys = SDL_GetKeyboardState(NULL);
    rdr.color = 0xffffffff;
    rdr.clearcolor = 0x000000;
    rdr.p1 = (SDL_Rect) {40, 40, 20, 80};
    rdr.p2 = (SDL_Rect) {580, 40, 20, 80};
    rdr.ball = (SDL_Rect) {315, 235, 10, 10};
    render(rdr.surface, rdr.ball, rdr.p1, rdr.p2, rdr.color);

    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event)) // only cares if we press quit, has nothing to do with keyboard state
        {
            running = quit(event, running);
        }

        paddleMovement(&rdr.p1, &rdr.p2, rdr.clearcolor, rdr.color, rdr.surface, rdr.keys);
        ballMovement(&rdr.ball, rdr.clearcolor, rdr.color, rdr.surface, &rdr.p1, &rdr.p2);

        SDL_UpdateWindowSurface(rdr.window);
        SDL_Delay(10);
    }
    
    SDL_Quit();
    return 0; // end of program
}