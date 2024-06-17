#ifndef KAMISADO_APPLIFECYCLEEVENTHANDLER_H
#define KAMISADO_APPLIFECYCLEEVENTHANDLER_H

#include "../events/AppLifeCycleEvent.h"

class AppLifeCycleEventHandler {
private:
    //SceneryEventTransmitter& sceneryEventTransmitter_;
public:
    void handle(AppLifeCycleEvent event);
};

#endif //KAMISADO_APPLIFECYCLEEVENTHANDLER_H
