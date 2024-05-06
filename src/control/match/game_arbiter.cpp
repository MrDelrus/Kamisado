#include "game_arbiter.h"
#include <iostream>

GameArbiter::GameArbiter(Arbiter& arbiter, const ArbiterViewer& arbiterViewer,
                         const SDL_Rect& board_rectangle, bool& isRunning) : arbiter_(arbiter),
                         arbiterViewer_(arbiterViewer), board_rectangle_(board_rectangle), isRunning_(isRunning) {}

void GameArbiter::handle(const SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        handle_mouse_click_();
    }

}

void GameArbiter::render() const {
    if (isChanged_) {
        isChanged_ = false;
        arbiterViewer_.draw();
    }
}

void GameArbiter::handle_mouse_click_() {

    int x, y;
    SDL_GetMouseState(&x, &y);

    if (board_rectangle_.x > x || board_rectangle_.x + board_rectangle_.w <= x ||
        board_rectangle_.y > y || board_rectangle_.y + board_rectangle_.h <= y) {
        return;
    }

    Position to = {(x - board_rectangle_.x) / (board_rectangle_.w / 8),
                         (board_rectangle_.y + board_rectangle_.h - y) / (board_rectangle_.h / 8)};

    Arbiter::Result result = move_to_position_(to);

    handle_move_result_(result);

}

Arbiter::Result GameArbiter::move_to_position_(const Position& to) {

    if (arbiter_.get_step() != Arbiter::Step::Waiting && (arbiter_.get_step() != Arbiter::Step::Preparing || to.second != 0)) {
        return arbiter_.move(to);
    }

    arbiter_.choose(to);
    return Arbiter::Result::First_turn;

}

void GameArbiter::handle_move_result_(const Arbiter::Result& result) {
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