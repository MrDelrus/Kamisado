#include "game_arbiter.h"

GameArbiter::GameArbiter(int width, int height, SDL_Renderer* renderer, bool& isRunning) : isRunning_(isRunning)
        , arbiter_(boardController_), arbiterViewer_(width, height, renderer, boardController_.get_board()) {}

void GameArbiter::handle() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            isRunning_ = false;
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
            isRunning_ = false;
        }
    }
}

void GameArbiter::render() {
    if (isChanged) {
        isChanged = false;
        arbiterViewer_.draw();
    }
}