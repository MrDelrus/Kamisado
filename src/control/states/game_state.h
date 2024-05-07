#ifndef KAMISADO_GAME_STATE_H
#define KAMISADO_GAME_STATE_H

#include <SDL.h>
#include "state.h"

class GameState {
public:
    virtual void update() = 0;
    virtual void render() const = 0;
    virtual State get_current_state() const = 0;
    virtual State get_next_state() const = 0;

    virtual ~GameState() = default;
};

#endif //KAMISADO_GAME_STATE_H
