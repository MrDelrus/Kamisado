#ifndef KAMISADO_TITLESCREENSCENERYEVENTHANDLER_H
#define KAMISADO_TITLESCREENSCENERYEVENTHANDLER_H

#include <memory>
#include "SceneryEventHandler.h"
#include "../states/TitleScreenScenery.h"

class TitleScreenSceneryEventHandler : public SceneryEventHandler {
private:
    std::shared_ptr<TitleScreenScenery> titleScreenScenery_;
public:
    explicit TitleScreenSceneryEventHandler(std::shared_ptr<TitleScreenScenery>);
    void handle(SceneryEvent) override;
};

#endif //KAMISADO_TITLESCREENSCENERYEVENTHANDLER_H
