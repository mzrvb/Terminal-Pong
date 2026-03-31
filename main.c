#include "pong.h"
// TO-DO 
// 1. Fix paddle speed
// 2. Get ball movement and bouncing
// 3.
// 4. 
static int MOVEMENT_SPEED = 10;

void playerMovement(SDL_Window * window, SDL_Rect * p1, Uint32 clearcolor, Uint32 color, SDL_Event event, SDL_Surface *surface)
{
    SDL_UpdateWindowSurface(window);

    if (event.type == SDL_KEYDOWN) // a key is pressed
    {
        int keypressed = event.key.keysym.scancode; // use scancode for physical key location
        SDL_FillRect(surface, &p1, clearcolor); // clear previous rectangle position

        if (keypressed == SDL_SCANCODE_DOWN)
        {
            p1->y+= 10;
        }
        else if (keypressed == SDL_SCANCODE_UP)
        {
            p1->y-= 10;
        }

        SDL_FillRect(surface, p1, color); // update p1 movement
    } 
}

int main(int argc, char* argv[]) { // SDL2 often requires these specific arguments for Windows compatibility

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    
    Uint32 color = 0xffffffff; // fill color
    Uint32 clearcolor = 0x000000; // clear color

    SDL_Rect p1 = (SDL_Rect) {40, 40, 20, 80}; // p1 
    SDL_FillRect(surface, &p1, color);

    /*SDL_Rect p2 = (SDL_Rect) {580, 40, 20, 80}; // p2
    SDL_FillRect(surface, &p2, color);*/

    SDL_Rect ball = (SDL_Rect) {315, 235, 10, 10}; // ball
    SDL_FillRect(surface, &ball, color);
    
    typedef struct Ball{
        int x;
        int y;
    } Ball;

    printf("%d", ball.y);

    // set top and bottom bounce conditions relative to ball spawnpoint
    // set conditions for the left and right of ball to see if hit paddle


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
            SDL_FillRect(surface, &p1, clearcolor); // clear previous rectangle position
            /*if (keypressed == SDL_SCANCODE_R) // refresh button for testing
            {
                SDL_Rect ball = (SDL_Rect) {315, 235, 10, 10}; // ball

            }*/
            if (keypressed == SDL_SCANCODE_DOWN)
            {
                p1.y+= 10;
            }
            else if (keypressed == SDL_SCANCODE_UP)
            {
                p1.y-= 10;
            }

            SDL_FillRect(surface, &p1, color); // update p1 movement
            SDL_FillRect(surface, &ball, color); // update ball movement
        } 
        SDL_UpdateWindowSurface(window);
    }
    
    SDL_Quit();
    return 0;
}