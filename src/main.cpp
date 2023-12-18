#include <iostream>
#include <SDL2/SDL.h>

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Kamisado",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if (!window) {
        std::cerr << "Failed to create window\n";
        return -1;
    }

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    if (!window_surface) {
        std::cerr << "Failed to get the surface from the window\n";
        return -1;
    }

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    return 0;
}