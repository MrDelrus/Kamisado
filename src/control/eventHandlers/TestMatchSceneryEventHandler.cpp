#include "TestMatchSceneryEventHandler.h"

TestMatchSceneryEventHandler::TestMatchSceneryEventHandler(std::shared_ptr<TestMatchScenery> testMatchScenery)
    : testMatchScenery_(std::move(testMatchScenery)) {}

void TestMatchSceneryEventHandler::handle(SceneryEvent sceneryEvent) {
    if (sceneryEvent.is_click) {

    } else {
        if (sceneryEvent.key == SceneryEvent::Key::Escape) {
            testMatchScenery_->set_next_state_(State::TitleScreen);
        }
    }
}
