#include "test_match_scenery.h"

TestMatchScenery::TestMatchScenery(const AssetManager& assetManager, const SDL_Rect& board_rectangle,
        const SDL_Rect& screen_rectangle) : isRunning_(true), boardController_(board_), assetManager_(assetManager),
        squareFiller_(assetManager_.get_renderer(), board_rectangle), pieceViewer_(assetManager_, board_rectangle),
        boardViewer_(assetManager_, board_rectangle), arbiter_(boardController_),
        arbiterViewer_(arbiter_, assetManager_, boardViewer_, pieceViewer_, squareFiller_, screen_rectangle),
        gameArbiter_(arbiter_, arbiterViewer_, board_rectangle, isRunning_) {}

void TestMatchScenery::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            next_state = State::Quit;
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            next_state = State::TitleScreen;
        } else {
            if (isRunning_) {
                gameArbiter_.handle(event);
                if (!isRunning_) {
                    next_state = State::TitleScreen;
                }
            }
        }
    }
}

void TestMatchScenery::render() const {
    gameArbiter_.render();
}

State TestMatchScenery::get_current_state() const {
    return State::TestMatch;
}

State TestMatchScenery::get_next_state() const {
    return next_state;
}
