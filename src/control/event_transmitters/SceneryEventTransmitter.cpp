#include "SceneryEventTransmitter.h"

SceneryEventTransmitter::SceneryEventTransmitter(StateMachine& stateMachine) : stateMachine_(stateMachine) {}

void SceneryEventTransmitter::handle(SceneryEvent) {
    return;
}

void SceneryEventTransmitter::handle(AppLifeCycleEvent event) {
    if (event == AppLifeCycleEvent::Quit) {
        stateMachine_.finish_();
    }
}