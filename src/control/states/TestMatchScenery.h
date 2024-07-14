#ifndef KAMISADO_TESTMATCHSCENERY_H
#define KAMISADO_TESTMATCHSCENERY_H

#include "GameState.h"
#include "../match/GameArbiter.h"
#include "../players/ProjectRunnerPlayer.h"
#include "../events/SceneryEvent.h"

class TestMatchScenery : public GameState {
private:
    bool isRunning_;
    Board board_;
    ProjectRunnerPlayer player1_;
    ProjectRunnerPlayer player2_;
    const AssetManager& assetManager_;
    SquareFiller squareFiller_;
    PieceViewer pieceViewer_;
    BoardViewer boardViewer_;
    ArbiterViewer arbiterViewer_;
    GameArbiter gameArbiter_;
    State next_state_ = State::TestMatch;
public:
    TestMatchScenery(const AssetManager&, SDL_Rect, SDL_Rect);

    void update() override;
    void render() const override;

    State get_current_state() const override;
    State get_next_state() const override;
    ~TestMatchScenery() override = default;
private:
    void set_next_state_(State state);

    friend class TestMatchSceneryEventHandler;
};

#endif //KAMISADO_TESTMATCHSCENERY_H
