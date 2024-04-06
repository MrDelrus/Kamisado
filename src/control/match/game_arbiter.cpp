#include "game_arbiter.h"
#include <iostream>

GameArbiter::GameArbiter(Arbiter& arbiter, const ArbiterViewer& arbiterViewer,
                         const SDL_Rect& board_rectangle, bool& isRunning) : arbiter_(arbiter),
                         arbiterViewer_(arbiterViewer), board_rectangle_(board_rectangle), isRunning_(isRunning) {}

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

            if (board_rectangle_.x > x || board_rectangle_.x + board_rectangle_.w <= x ||
                board_rectangle_.y > y || board_rectangle_.y + board_rectangle_.h <= y) {
                continue;
            }

            Position position = {(x - board_rectangle_.x) / (board_rectangle_.w / 8),
                                 (board_rectangle_.y + board_rectangle_.h - y) / (board_rectangle_.h / 8)};

            if (arbiter_.get_step() == Arbiter::Step::Waiting) {
                arbiter_.choose(position);
            } else {
                if (arbiter_.get_step() == Arbiter::Step::Preparing && position.second == 0) {
                    arbiter_.choose(position);
                } else {
                    Arbiter::Result result = arbiter_.move(position);
                    if (result != Arbiter::Result::Failed) {
                        isChanged_ = true;
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

void GameArbiter::render() {
    if (isChanged_) {
        isChanged_ = false;
        arbiterViewer_.draw();
    }
}