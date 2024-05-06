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
    mutable bool isChanged_ = true;

private:
    void handle_mouse_click_();
    Arbiter::Result move_to_position_(const Position&);
    void handle_move_result_(const Arbiter::Result&);
public:
    GameArbiter(Arbiter&, const ArbiterViewer&, const SDL_Rect& board_rectangle, bool&);
    void handle(const SDL_Event& event);
    void render() const;
};

#endif //KAMISADO_GAME_ARBITER_H
