#include "title_screen_scenery.h"
#include <iostream>

TitleScreenScenery::TitleScreenScenery(const AssetManager& assetManager, const SDL_Rect& screen_rectangle) :
        assetManager_(assetManager), screen_rectangle_(screen_rectangle) {}

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
    SDL_Renderer* renderer = assetManager_.get_renderer();
    SDL_RenderClear(renderer);
    std::cerr << "Rendering title screen\t";
    SDL_RenderCopy(renderer, assetManager_.get_title_screen_image(), nullptr, &screen_rectangle_);
    std::cerr << "Done\n";
    SDL_RenderPresent(renderer);
}

State TitleScreenScenery::get_current_state() const {
    return State::TitleScreen;
}

State TitleScreenScenery::get_next_state() const {
    return next_state;
}


