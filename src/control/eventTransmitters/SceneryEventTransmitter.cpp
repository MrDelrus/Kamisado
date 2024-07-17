#include "SceneryEventTransmitter.h"

SceneryEventTransmitter::SceneryEventTransmitter(StateMachine& stateMachine) : stateMachine_(stateMachine) {}

void SceneryEventTransmitter::handle(SceneryEvent event) {
    stateMachine_.currentSceneryEventHandler_->handle(event);
}

void SceneryEventTransmitter::handle(AppLifeCycleEvent event) {
    if (event == AppLifeCycleEvent::Quit) {
        stateMachine_.finish_();
    }
}