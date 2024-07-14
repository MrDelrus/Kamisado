#ifndef KAMISADO_STATEMACHINE_H
#define KAMISADO_STATEMACHINE_H

#include "GameState.h"
#include "State.h"
#include "TestMatchScenery.h"
#include "TitleScreenScenery.h"

class StateMachine {
private:
    const AssetManager& assetManager_;
    const int WIDTH_;
    const int HEIGHT_;
    State current_state_;
    GameState* current_scenery_ = nullptr;
public:
    StateMachine(const AssetManager&, int, int);
    void update();
    void render() const;
    bool running() const;
    ~StateMachine();
private:
    void finish_();
    void change_state_(State);

    friend class SceneryEventTransmitter;
};

#endif //KAMISADO_STATEMACHINE_H
