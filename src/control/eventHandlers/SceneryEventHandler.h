#ifndef KAMISADO_SCENERYEVENTHANDLER_H
#define KAMISADO_SCENERYEVENTHANDLER_H

#include "../events/SceneryEvent.h"

class SceneryEventHandler {
public:
    virtual void handle(SceneryEvent) = 0;

    virtual ~SceneryEventHandler() = default;
};

#endif //KAMISADO_SCENERYEVENTHANDLER_H
