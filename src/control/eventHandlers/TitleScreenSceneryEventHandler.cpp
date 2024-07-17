#include "TitleScreenSceneryEventHandler.h"

TitleScreenSceneryEventHandler::TitleScreenSceneryEventHandler(std::shared_ptr<TitleScreenScenery> titleScreenScenery)
    : titleScreenScenery_(std::move(titleScreenScenery)) {}

void TitleScreenSceneryEventHandler::handle(SceneryEvent sceneryEvent) {
    if (sceneryEvent.is_click) {
        titleScreenScenery_->set_next_state_(State::TestMatch);
    } else {
        if (sceneryEvent.key == SceneryEvent::Key::Escape) {
            titleScreenScenery_->set_next_state_(State::Quit);
        }
        if (sceneryEvent.key == SceneryEvent::Key::Enter) {
            titleScreenScenery_->set_next_state_(State::TestMatch);
        }
    }
}