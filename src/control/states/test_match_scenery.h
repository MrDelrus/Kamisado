#ifndef KAMISADO_TEST_MATCH_SCENERY_H
#define KAMISADO_TEST_MATCH_SCENERY_H

#include "game_state.h"
#include "../match/game_arbiter.h"

class TestMatchScenery : public GameState {
private:
    bool isRunning_;
    Board board_;
    BoardController boardController_;
    AssetManager assetManager_;
    SquareFiller squareFiller_;
    PieceViewer pieceViewer_;
    BoardViewer boardViewer_;
    Arbiter arbiter_;
    ArbiterViewer arbiterViewer_;
    GameArbiter gameArbiter_;
    State next_state = State::TestMatch;
public:
    TestMatchScenery(SDL_Renderer* renderer, const SDL_Rect& board_rectangle, const SDL_Rect& screen_rectangle);

    void update() override;
    void render() const override;

    State get_current_state() const override;
    State get_next_state() const override;
};

#endif //KAMISADO_TEST_MATCH_SCENERY_H
