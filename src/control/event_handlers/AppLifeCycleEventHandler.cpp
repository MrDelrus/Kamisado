#include "AppLifeCycleEventHandler.h"

AppLifeCycleEventHandler::AppLifeCycleEventHandler(SceneryEventTransmitter& sceneryEventTransmitter) :
    sceneryEventTransmitter_(sceneryEventTransmitter) {}

void AppLifeCycleEventHandler::handle(AppLifeCycleEvent event) {
    if (event == AppLifeCycleEvent::Quit) {
        sceneryEventTransmitter_.handle(event);
    }
}