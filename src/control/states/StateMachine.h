#ifndef KAMISADO_STATEMACHINE_H
#define KAMISADO_STATEMACHINE_H

#include <memory>
#include "GameState.h"
#include "State.h"
#include "TestMatchScenery.h"
#include "TitleScreenScenery.h"
#include "../eventHandlers/SceneryEventHandler.h"
#include "../eventHandlers/TitleScreenSceneryEventHandler.h"
#include "../eventHandlers/TestMatchSceneryEventHandler.h"

class StateMachine {
private:
    const AssetManager& assetManager_;
    const int WIDTH_;
    const int HEIGHT_;
    State currentState_;
    std::shared_ptr<GameState> currentScenery_;
    std::shared_ptr<SceneryEventHandler> currentSceneryEventHandler_;
public:
    StateMachine(const AssetManager&, int, int);
    void update();
    void render() const;
    bool running() const;
private:
    void finish_();
    void change_state_(State);

    friend class SceneryEventTransmitter;
};

#endif //KAMISADO_STATEMACHINE_H
