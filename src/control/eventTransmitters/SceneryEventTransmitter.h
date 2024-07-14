#ifndef KAMISADO_SCENERYEVENTTRANSMITTER_H
#define KAMISADO_SCENERYEVENTTRANSMITTER_H

#include "../events/SceneryEvent.h"
#include "../events/AppLifeCycleEvent.h"
#include "../states/StateMachine.h"

class SceneryEventTransmitter {
private:
    StateMachine& stateMachine_;
public:
    explicit SceneryEventTransmitter(StateMachine&);
    void handle(SceneryEvent);
    void handle(AppLifeCycleEvent);
};

#endif //KAMISADO_SCENERYEVENTTRANSMITTER_H
