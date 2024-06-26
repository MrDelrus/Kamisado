#include <iostream>
#include "state_machine.h"

StateMachine::StateMachine(const AssetManager& assetManager, int width, int height) : assetManager_(assetManager),
        WIDTH_(width), HEIGHT_(height), current_state_(State::TitleScreen) {
    SDL_Rect screen_rectangle;
    screen_rectangle.x = 0;
    screen_rectangle.y = 0;
    screen_rectangle.w = WIDTH_;
    screen_rectangle.h = HEIGHT_;

    current_scenery_ = new TitleScreenScenery(assetManager_, screen_rectangle);
}

void StateMachine::update() {
    if (!current_scenery_) {
        return;
    }
    current_scenery_->update();
    State next_state = current_scenery_->get_next_state();
    if (next_state != current_scenery_->get_current_state()) {
        delete current_scenery_;
        if (next_state == State::Quit) {
            current_state_ = State::Quit;
            current_scenery_ = nullptr;
        } else if (next_state == State::TestMatch) {
            SDL_Rect screen_rectangle;
            screen_rectangle.x = 0;
            screen_rectangle.y = 0;
            screen_rectangle.w = WIDTH_;
            screen_rectangle.h = HEIGHT_;

            SDL_Rect board_rectangle;
            board_rectangle.x = WIDTH_ / 16;
            board_rectangle.y = HEIGHT_ / 16;
            board_rectangle.w = HEIGHT_ - board_rectangle.y * 2;
            board_rectangle.h = board_rectangle.w;

            current_state_ = State::TestMatch;
            current_scenery_ = new TestMatchScenery(assetManager_, board_rectangle, screen_rectangle);
        } else if (next_state == State::TitleScreen) {
            SDL_Rect screen_rectangle;
            screen_rectangle.x = 0;
            screen_rectangle.y = 0;
            screen_rectangle.w = WIDTH_;
            screen_rectangle.h = HEIGHT_;

            current_state_ = State::TitleScreen;
            current_scenery_ = new TitleScreenScenery(assetManager_, screen_rectangle);
        }
    }
}

void StateMachine::render() const {
    if (current_scenery_) {
        current_scenery_->render();
    }
}

bool StateMachine::running() const {
    return current_state_ != State::Quit;
}

StateMachine::~StateMachine() {
    delete current_scenery_;
}
