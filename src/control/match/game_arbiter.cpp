#include "game_arbiter.h"
#include <iostream>

GameArbiter::GameArbiter(int width, int height, SDL_Renderer* renderer, bool& isRunning) : isRunning_(isRunning)
        , arbiter_(boardController_), arbiterViewer_(width, height, renderer, boardController_.get_board())
        , clickController_(width, height) {}

void GameArbiter::handle() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            isRunning_ = false;
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
            isRunning_ = false;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            Position position = clickController_.get_position(x, y);
            if (position.first >= 0 && position.first <= 7 && position.second >= 0 && position.second <= 7) {
                if (arbiter_.get_step() == Arbiter::Step::Waiting) {
                    arbiter_.choose(position);
                } else {
                    if (arbiter_.get_step() == Arbiter::Step::Preparing && position.second == 0) {
                        arbiter_.choose(position);
                    } else {
                        Arbiter::Result result = arbiter_.move(position);
                        if (result != Arbiter::Result::Failed) {
                            isChanged = true;
                            if (result == Arbiter::Result::First_wins) {
                                std::cout << "FIRST WON" << std::endl;
                                isRunning_ = false;
                            } else if (result == Arbiter::Result::Second_wins) {
                                std::cout << "SECOND WON" << std::endl;
                                isRunning_ = false;
                            }
                        }
                    }
                }
            }
        }
    }
}

void GameArbiter::render() {
    if (isChanged) {
        isChanged = false;
        arbiterViewer_.draw();
    }
}