#include "TestMatchSceneryEventHandler.h"

void TestMatchSceneryEventHandler::handle(SceneryEvent sceneryEvent) {
    if (!sceneryEvent.is_click) {
        if (sceneryEvent.key == -1) {
            testMatchScenery_.set_next_state_(State::TitleScreen);
        }
    }
}
