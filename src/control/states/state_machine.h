#ifndef KAMISADO_STATE_MACHINE_H
#define KAMISADO_STATE_MACHINE_H

#include "game_state.h"
#include "state.h"
#include "test_match_scenery.h"
#include "title_screen_scenery.h"

class StateMachine {
private:
    SDL_Renderer* renderer_;
    const int WIDTH_;
    const int HEIGHT_;
    State current_state_;
    GameState* current_scenery_ = nullptr;
public:
    StateMachine(SDL_Renderer* renderer, int width, int height);
    void update();
    void render() const;
    bool running() const;
    ~StateMachine();
};

#endif //KAMISADO_STATE_MACHINE_H
