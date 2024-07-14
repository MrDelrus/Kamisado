#ifndef KAMISADO_APPLIFECYCLEEVENTHANDLER_H
#define KAMISADO_APPLIFECYCLEEVENTHANDLER_H

#include "../events/AppLifeCycleEvent.h"
#include "../eventTransmitters/SceneryEventTransmitter.h"

class AppLifeCycleEventHandler {
private:
    SceneryEventTransmitter& sceneryEventTransmitter_;
public:
    AppLifeCycleEventHandler(SceneryEventTransmitter&);
    void handle(AppLifeCycleEvent event);
};

#endif //KAMISADO_APPLIFECYCLEEVENTHANDLER_H
