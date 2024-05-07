#ifndef KAMISADO_TITLE_SCREEN_SCENERY_H
#define KAMISADO_TITLE_SCREEN_SCENERY_H

#include "game_state.h"
#include "../../view/match/asset_manager.h"

class TitleScreenScenery : public GameState {
private:
    const AssetManager& assetManager_;
    const SDL_Rect screen_rectangle_;
    State next_state = State::TitleScreen;
    mutable bool isChanged_ = true;
public:
    TitleScreenScenery(const AssetManager&, SDL_Rect);

    void update() override;
    void render() const override;

    State get_current_state() const override;
    State get_next_state() const override;
};

#endif //KAMISADO_TITLE_SCREEN_SCENERY_H
