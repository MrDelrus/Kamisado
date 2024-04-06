#ifndef KAMISADO_GAME_ARBITER_H
#define KAMISADO_GAME_ARBITER_H

#include "arbiter.h"
#include "../../view/match/arbiter_viewer.h"

class GameArbiter {
private:
    Arbiter& arbiter_;
    const ArbiterViewer& arbiterViewer_;
    const SDL_Rect& board_rectangle_;
    bool& isRunning_;
    bool isChanged_ = true;
public:
    GameArbiter(Arbiter&, const ArbiterViewer&, const SDL_Rect& board_rectangle, bool&);
    void handle();
    void render();
};

#endif //KAMISADO_GAME_ARBITER_H
