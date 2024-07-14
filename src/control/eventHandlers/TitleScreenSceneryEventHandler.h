#ifndef KAMISADO_TITLESCREENSCENERYEVENTHANDLER_H
#define KAMISADO_TITLESCREENSCENERYEVENTHANDLER_H

#include "SceneryEventHandler.h"
#include "../states/TitleScreenScenery.h"

class TitleScreenSceneryEventHandler : public SceneryEventHandler {
private:
    TitleScreenScenery& titleScreenScenery;
public:
    void handle(SceneryEvent) override;
};

#endif //KAMISADO_TITLESCREENSCENERYEVENTHANDLER_H
