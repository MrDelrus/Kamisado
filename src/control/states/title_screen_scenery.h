#ifndef KAMISADO_TITLE_SCREEN_SCENERY_H
#define KAMISADO_TITLE_SCREEN_SCENERY_H

#include "game_state.h"

class TitleScreenScenery : public GameState {
private:
    SDL_Renderer* renderer_;
    const SDL_Rect& screen_rectangle_;
    State next_state = State::TitleScreen;
public:
    TitleScreenScenery(SDL_Renderer* renderer, const SDL_Rect& screen_rectangle);

    void update() override;
    void render() const override;

    State get_current_state() const override;
    State get_next_state() const override;
};

#endif //KAMISADO_TITLE_SCREEN_SCENERY_H
