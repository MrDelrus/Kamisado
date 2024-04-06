#ifndef KAMISADO_GAME_ARBITER_H
#define KAMISADO_GAME_ARBITER_H

#include "arbiter.h"
#include "../../view/arbiter_viewer.h"
#include "click_controller.h"

class GameArbiter {
private:
    BoardController& boardController_;
    Arbiter& arbiter_;
    const ArbiterViewer& arbiterViewer_;
    const ClickController& clickController_;
    bool& isRunning_;
    bool isChanged_ = true;
public:
    GameArbiter(BoardController&, Arbiter&, const ArbiterViewer&, const ClickController&, bool&);
    void handle();
    void render();
};

#endif //KAMISADO_GAME_ARBITER_H
