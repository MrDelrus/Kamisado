#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "view/board_viewer.h"

void DeInit(int error) {
    IMG_Quit();
    SDL_Quit();
    exit(error);
}

void Init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize the SDL2 library\n";
        DeInit(1);
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "Failed to initialize images library\n";
        DeInit(1);
    }
}

const int FPS = 60;

int main() {

    Init();

    const int WIDTH = 800;
    const int HEIGHT = 600;

    SDL_Window* window = SDL_CreateWindow("Kamisado",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT,
                                          0);

    if (!window) {
        std::cerr << "Failed to create window\n";
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    if (!window_surface) {
        std::cerr << "Failed to get the surface from the window\n";
        return -1;
    }

    BoardViewer boardViewer;
    bool isRunning = true;

    SDL_RenderClear(renderer);

    boardViewer.draw(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(2000);

    /*
    while (isRunning) {

        //SDL_RenderClear(renderer);

        //SDL_Delay(1000 / FPS);

        //SDL_Delay(5000);
        //isRunning = false;

    } */

    DeInit(0);

    return 0;
}