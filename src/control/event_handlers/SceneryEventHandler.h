#ifndef KAMISADO_SCENERYEVENTHANDLER_H
#define KAMISADO_SCENERYEVENTHANDLER_H

#include "../events/SceneryEvent.h"

class SceneryEventHandler {
public:
    void handle(SceneryEvent) = delete;
};

#endif //KAMISADO_SCENERYEVENTHANDLER_H
