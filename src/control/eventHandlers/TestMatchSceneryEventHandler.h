#ifndef KAMISADO_TESTMATCHSCENERYEVENTHANDLER_H
#define KAMISADO_TESTMATCHSCENERYEVENTHANDLER_H

#include <memory>
#include "SceneryEventHandler.h"
#include "../states/TestMatchScenery.h"

class TestMatchSceneryEventHandler : public SceneryEventHandler {
private:
    std::shared_ptr<TestMatchScenery> testMatchScenery_;
public:
    explicit TestMatchSceneryEventHandler(std::shared_ptr<TestMatchScenery>);
    void handle(SceneryEvent) override;
};

#endif //KAMISADO_TESTMATCHSCENERYEVENTHANDLER_H
