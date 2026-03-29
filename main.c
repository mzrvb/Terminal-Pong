#include "pong.h"

int main(int argc, char* argv[]) { // SDL2 often requires these specific arguments for Windows compatibility
    // 1. Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        return 1; 
    }

    // 2. Create the Window
    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    
    if (!window) {
        SDL_Quit();
        return 1;
    }

    // 3. Get the Surface
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    
    // 4. Define and Draw the Rect
    SDL_Rect rect = {40, 40, 40, 90}; // Simplified initialization
    Uint32 color = SDL_MapRGB(surface->format, 255, 255, 255); // Safer way to handle color
    
    SDL_FillRect(surface, &rect, color);
    
    // 5. THE MISSING PIECE: Push the memory to the screen
    SDL_UpdateWindowSurface(window);

    // 6. Wait and Cleanup
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