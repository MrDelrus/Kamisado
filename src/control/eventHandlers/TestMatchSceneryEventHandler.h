#ifndef KAMISADO_TESTMATCHSCENERYEVENTHANDLER_H
#define KAMISADO_TESTMATCHSCENERYEVENTHANDLER_H

#include "SceneryEventHandler.h"
#include "../states/TestMatchScenery.h"

class TestMatchSceneryEventHandler : public SceneryEventHandler {
private:
    TestMatchScenery& testMatchScenery_;
public:
    void handle(SceneryEvent) override;
};

#endif //KAMISADO_TESTMATCHSCENERYEVENTHANDLER_H
