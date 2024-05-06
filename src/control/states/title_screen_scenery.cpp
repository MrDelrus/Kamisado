//
// Created by mrdelrus on 06.05.24.
//

#include "title_screen_scenery.h"

TitleScreenScenery::TitleScreenScenery(SDL_Renderer* renderer, const SDL_Rect& screen_rectangle) : renderer_(renderer),
        screen_rectangle_(screen_rectangle) {}

void TitleScreenScenery::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            next_state = State::Quit;
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            next_state = State::Quit;
        } else {
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                next_state = State::TestMatch;
            }
        }
    }
}

void TitleScreenScenery::render() const {
    SDL_RenderClear(renderer_);
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer_, &screen_rectangle_);
    SDL_RenderPresent(renderer_);
}

State TitleScreenScenery::get_current_state() const {
    return State::TitleScreen;
}

State TitleScreenScenery::get_next_state() const {
    return next_state;
}


