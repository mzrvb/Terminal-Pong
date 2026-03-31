#include "pong.h"
// TO-DO 
// 1. Fix paddle speed
// 2. Get ball movement and bouncing
// 3.
// 4. 
static int MOVEMENT_SPEED = 10;

void playerMovement(SDL_Rect * player, Uint32 clearcolor, Uint32 color, SDL_Event event, SDL_Surface *surface, int playerbtn)
{
    if (event.type == SDL_KEYDOWN)
    {
        int keypressed = event.key.keysym.scancode; // use scancode for physical key location
        SDL_FillRect(surface, player, clearcolor); // clear previous rectangle position

        if (playerbtn == 1) // player one controls
        {
            if (keypressed == SDL_SCANCODE_DOWN)
            {
                player->y+= 10;
            }
            else if (keypressed == SDL_SCANCODE_UP)
            {
                player->y-= 10;
            }
        }
        else if (playerbtn == 2) // player two controls
        {
            if (keypressed == SDL_SCANCODE_N)
            {
                player->y+= 10;
            }
            else if (keypressed == SDL_SCANCODE_H)
            {
                player->y-= 10;
            }
        }
        
        SDL_FillRect(surface, player, color); // update p1 movement
    } 
}

int quit(SDL_Event event, int running)
{
    if (event.type == SDL_QUIT)
    {
        printf("quit\n");
        return running = 0;
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

    SDL_Rect p2 = (SDL_Rect) {580, 40, 20, 80}; // p2
    SDL_FillRect(surface, &p2, color);

    SDL_Rect ball = (SDL_Rect) {315, 235, 10, 10}; // ball
    SDL_FillRect(surface, &ball, color);
    
    typedef struct Ball{
        int x;
        int y;
    } Ball;

    printf("%d", ball.y);

    // set top and bottom bounce conditions relative to ball spawnpoint
    // set conditions for the left and right of ball to see if hit paddle
    int running = 1;
    SDL_Event event;

    while (running)
    {
        SDL_PollEvent(&event); // check the event queue, execute the latest event
        
        running = quit(event, running);
        playerMovement(&p1, clearcolor, color, event, surface, 1);
        playerMovement(&p2, clearcolor, color, event, surface, 2);

        SDL_UpdateWindowSurface(window);
    }
    
    SDL_Quit();
    return 0;
}