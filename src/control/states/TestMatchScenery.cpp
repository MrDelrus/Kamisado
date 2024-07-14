#include "TestMatchScenery.h"

TestMatchScenery::TestMatchScenery(const AssetManager& assetManager, SDL_Rect board_rectangle,
        SDL_Rect screen_rectangle) : isRunning_(true), player1_(board_rectangle), player2_(board_rectangle),
        assetManager_(assetManager), squareFiller_(assetManager_.get_renderer(), board_rectangle),
        pieceViewer_(assetManager_, board_rectangle), boardViewer_(assetManager_, board_rectangle),
        arbiterViewer_(board_, assetManager_, boardViewer_, pieceViewer_, squareFiller_, screen_rectangle),
        gameArbiter_(player1_, player2_, board_) {}

void TestMatchScenery::update() {
    std::string result = gameArbiter_.update();
    if (result == "QUIT") {
        set_next_state_(State::Quit);
    } else if (result == "END") {
        set_next_state_(State::TitleScreen);
    }
}

void TestMatchScenery::render() const {
    arbiterViewer_.draw();
}

State TestMatchScenery::get_current_state() const {
    return State::TestMatch;
}

State TestMatchScenery::get_next_state() const {
    return next_state_;
}

void TestMatchScenery::set_next_state_(State state) {
    next_state_ = state;
}
