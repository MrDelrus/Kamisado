#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <chrono>
#include <thread>

#include "control/states/state_machine.h"

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

const int WIDTH = 256 * 4;
const int HEIGHT = 256 * 3;

const int FPS = 60;
const std::chrono::milliseconds frameDuration(1000 / FPS);


int main() {

    Init();

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
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    StateMachine stateMachine(renderer, WIDTH, HEIGHT);

    auto begin = std::chrono::high_resolution_clock::now();

    int ticks = 0;

    while (stateMachine.running()) {

        auto start = std::chrono::high_resolution_clock::now();

        stateMachine.update();
        ticks += 1;
        stateMachine.render();

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::chrono::milliseconds remaining = frameDuration - duration;

        if (remaining.count() > 0) {
            std::this_thread::sleep_for(remaining);
        }

    }

    std::cerr << "Frames count : " <<  ticks << std::endl;

    SDL_DestroyWindow(window);
    DeInit(0);

    return 0;
}