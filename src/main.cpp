#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <chrono>
#include <thread>

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
const std::chrono::milliseconds frameDuration(1000 / FPS);

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

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);

    Board board;
    ArbiterViewer arbiterViewer(WIDTH, HEIGHT, renderer);

    bool isRunning = true;
    bool changes = true;

    auto begin = std::chrono::high_resolution_clock::now();

    int ticks = 0;

    while (isRunning) {

        auto start = std::chrono::high_resolution_clock::now();

        ticks += 1;
        if (changes) {
            arbiterViewer.draw(board);
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::chrono::milliseconds remaining = frameDuration - duration;

        if (remaining.count() > 0) {
            std::this_thread::sleep_for(remaining);
        }

        if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() > 1000) {
            isRunning = false;
        }

    }

    std::cerr << ticks << std::endl;

    SDL_DestroyWindow(window);
    DeInit(0);

    return 0;
}