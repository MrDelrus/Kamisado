#ifndef KAMISADO_TITLESCREENSCENERY_H
#define KAMISADO_TITLESCREENSCENERY_H

#include "GameState.h"
#include "../../view/match/AssetManager.h"

class TitleScreenScenery : public GameState {
private:
    const AssetManager& assetManager_;
    const SDL_Rect screen_rectangle_;
    State next_state_ = State::TitleScreen;
    mutable bool isChanged_ = true;
public:
    TitleScreenScenery(const AssetManager&, SDL_Rect);

    void update() override;
    void render() const override;

    State get_current_state() const override;
    State get_next_state() const override;
private:
    void set_next_state_(State state) override;

    friend class TitleScreenSceneryEventHandler;
};

#endif //KAMISADO_TITLESCREENSCENERY_H
