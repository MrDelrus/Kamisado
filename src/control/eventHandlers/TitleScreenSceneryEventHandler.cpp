#include "TitleScreenSceneryEventHandler.h"

void TitleScreenSceneryEventHandler::handle(SceneryEvent sceneryEvent) {
    if (!sceneryEvent.is_click) {
        if (sceneryEvent.key == -1) {
            titleScreenScenery.set_next_state_(State::Quit);
        }
    } else {
        int x = sceneryEvent.x_click;
        int y = sceneryEvent.y_click;
        SDL_Rect start_button_rectangle = titleScreenScenery.start_button_rectangle_;
        if (x >= start_button_rectangle.x && x <= start_button_rectangle.x + start_button_rectangle.w &&
            y >= start_button_rectangle.y && y <= start_button_rectangle.y + start_button_rectangle.h) {
            titleScreenScenery.set_next_state_(State::TestMatch);
        }
    }
}