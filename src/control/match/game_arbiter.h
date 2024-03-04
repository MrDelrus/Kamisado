#ifndef KAMISADO_GAME_ARBITER_H
#define KAMISADO_GAME_ARBITER_H

#include "arbiter.h"
#include "../../view/arbiter_viewer.h"

class GameArbiter {
private:
    bool& isRunning_;
    bool isChanged;
    BoardController boardController_;
    Arbiter arbiter_;
    ArbiterViewer arbiterViewer_;
public:
    GameArbiter(int, int, SDL_Renderer*, bool&);
    void handle();
    void render();
};

#endif //KAMISADO_GAME_ARBITER_H