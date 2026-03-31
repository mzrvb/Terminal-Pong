#include "pong.h"

int main(int argc, char* argv[]) { // SDL2 often requires these specific arguments for Windows compatibility

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    
    Uint32 color = 0xffffffff; // fill color
    Uint32 clearcolor = 0x000000; // clear color

    SDL_Rect p1 = (SDL_Rect) {40, 40, 20, 80}; // p1 
    SDL_FillRect(surface, &p1, color);

    SDL_Rect p2 = (SDL_Rect) {580, 40, 20, 80}; // p2
    SDL_FillRect(surface, &p2, color);

    SDL_UpdateWindowSurface(window);

    int running = 1;
    SDL_Event event;

    while (running)
    {
        SDL_PollEvent(&event); // check the event queue, execute the latest event
        if (event.type == SDL_QUIT)
        {
            printf("quit\n");
            running = 0;
        }
        if (event.type == SDL_KEYDOWN) // a key is pressed
        {
            int keypressed = event.key.keysym.scancode; // use scancode for physical key location

            if (keypressed == SDL_SCANCODE_DOWN)
            {
                SDL_FillRect(surface, &p1, clearcolor); // clear old rectangle position
                printf("downbutton\n");
                p1.y+= 10;
            }
            else if (keypressed == SDL_SCANCODE_UP)
            {
                SDL_FillRect(surface, &p1, clearcolor); // clear old rectangle position
                printf("upbutton\n");
                p1.y-= 10;
            }

            SDL_UpdateWindowSurface(window);
            SDL_FillRect(surface, &p1, color); // update new rectangle
        } 

        SDL_UpdateWindowSurface(window);
    }
    
    SDL_Quit();
    return 0;
}