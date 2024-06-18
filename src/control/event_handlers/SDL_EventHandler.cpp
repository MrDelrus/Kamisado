#include "SDL_EventHandler.h"
#include "../events/AppLifeCycleEvent.h"

SDL_EventHandler::SDL_EventHandler(AppLifeCycleEventHandler& appLifeCycleEventHandler, SceneryEventHandler*
    sceneryEventHandler) : appLifeCycleEventHandler_(appLifeCycleEventHandler), sceneryEventHandler_(
    sceneryEventHandler) {}

void SDL_EventHandler::handle() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            appLifeCycleEventHandler_.handle(AppLifeCycleEvent::Quit);
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            SceneryEvent sceneryEvent;
            sceneryEvent.is_click = false;
            sceneryEvent.key = -1;
            sceneryEventHandler_->handle(sceneryEvent);
        } else {
            if (isRunning_) {
                gameArbiter_.handle(event);
                if (!isRunning_) {
                    next_state = State::TitleScreen;
                }
            }
        } */
    }
}