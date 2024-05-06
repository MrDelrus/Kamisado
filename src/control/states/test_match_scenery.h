#ifndef KAMISADO_TEST_MATCH_SCENERY_H
#define KAMISADO_TEST_MATCH_SCENERY_H

#include "game_state.h"
#include "../match/game_arbiter.h"

class TestMatchScenery : public GameState {
private:
    bool isRunning_;
    Board board_;
    BoardController boardController_;
    const AssetManager& assetManager_;
    SquareFiller squareFiller_;
    PieceViewer pieceViewer_;
    BoardViewer boardViewer_;
    Arbiter arbiter_;
    ArbiterViewer arbiterViewer_;
    GameArbiter gameArbiter_;
    State next_state = State::TestMatch;
public:
    TestMatchScenery(const AssetManager&, const SDL_Rect&, const SDL_Rect&);

    void update() override;
    void render() const override;

    State get_current_state() const override;
    State get_next_state() const override;
};

#endif //KAMISADO_TEST_MATCH_SCENERY_H
