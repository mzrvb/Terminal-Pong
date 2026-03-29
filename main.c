#include "pong.h"

int main(int argc, char* argv[]) { // SDL2 often requires these specific arguments for Windows compatibility

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    

    SDL_Rect p1 = (SDL_Rect) {40, 40, 40, 200}; // p1 
    SDL_Rect p2 = (SDL_Rect) {200, 40, 40, 200}; // p2
    Uint32 color = 0xffffffff; // fill color
    
    SDL_FillRect(surface, &p1, color);
    SDL_FillRect(surface, &p2, color);

    // static image of window surface with p1 and p2
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

/*
int main(){   // godbless sdl2 documentation
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Rect rect = (SDL_Rect) {40, 40, 40, 40};
    
    Uint32 color = 0xffffffff;
    SDL_FillRect(surface, &rect, color);
    SDL_Delay(5000);
}*/