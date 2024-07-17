#include "StateMachine.h"

StateMachine::StateMachine(const AssetManager& assetManager, int width, int height) : assetManager_(assetManager),
    WIDTH_(width), HEIGHT_(height), currentState_(State::TitleScreen) {
    change_state_(State::TitleScreen);
}

void StateMachine::update() {
    if (!currentScenery_) {
        return;
    }
    currentScenery_->update();
    State next_state = currentScenery_->get_next_state();
    if (next_state != currentScenery_->get_current_state()) {
        change_state_(next_state);
    }
}

void StateMachine::render() const {
    if (currentScenery_) {
        currentScenery_->render();
    }
}

bool StateMachine::running() const {
    return currentState_ != State::Quit;
}

void StateMachine::finish_() {
    change_state_(State::Quit);
}

void StateMachine::change_state_(State state) {
    currentState_ = state;
    if (state == State::Quit) {
        currentScenery_ = nullptr;
        currentSceneryEventHandler_ = nullptr;
    } else if (state == State::TestMatch) {
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

        currentScenery_ = std::make_shared<TestMatchScenery>(assetManager_, board_rectangle, screen_rectangle);
        currentSceneryEventHandler_ = std::make_shared<TestMatchSceneryEventHandler>(
                std::dynamic_pointer_cast<TestMatchScenery>(currentScenery_));
    } else if (state == State::TitleScreen) {
        SDL_Rect screen_rectangle;
        screen_rectangle.x = 0;
        screen_rectangle.y = 0;
        screen_rectangle.w = WIDTH_;
        screen_rectangle.h = HEIGHT_;

        currentScenery_ = std::make_shared<TitleScreenScenery>(assetManager_, screen_rectangle);
        currentSceneryEventHandler_ = std::make_shared<TitleScreenSceneryEventHandler>(
                std::dynamic_pointer_cast<TitleScreenScenery>(currentScenery_));
    }
}