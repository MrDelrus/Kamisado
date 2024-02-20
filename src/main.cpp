#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "view/arbiter_viewer.h"

void DeInit(int error, int step = 2) {
    if (step >= 1) {
        IMG_Quit();
    }
    if (step >= 0) {
        SDL_Quit();
    }
    exit(error);
}

void Init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize the SDL2 library\n";
        DeInit(1, 0);
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "Failed to initialize images library\n";
        DeInit(1, 1);
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

    Board board;
    ArbiterViewer arbiterViewer(WIDTH, HEIGHT, renderer);

    bool isRunning = true;
    bool changes = true;

    while (isRunning) {

        if (changes) {
            arbiterViewer.draw(board);
        }

        SDL_Delay(1000);

        isRunning = false;

    }

    SDL_DestroyWindow(window);
    DeInit(0);

    return 0;
}