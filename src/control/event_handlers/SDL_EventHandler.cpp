#include "SDL_EventHandler.h"
#include "../events/AppLifeCycleEvent.h"
#include <iostream>

SDL_EventHandler::SDL_EventHandler(AppLifeCycleEventHandler& appLifeCycleEventHandler, SceneryEventTransmitter&
    sceneryEventTransmitter) : appLifeCycleEventHandler_(appLifeCycleEventHandler), sceneryEventTransmitter_(
    sceneryEventTransmitter) {}

void SDL_EventHandler::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            std::cerr << "QUIT" << std::endl;
            appLifeCycleEventHandler_.handle(AppLifeCycleEvent::Quit);
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            SceneryEvent sceneryEvent;
            sceneryEvent.is_click = false;
            sceneryEvent.key = -1;
            sceneryEventTransmitter_.handle(sceneryEvent);
        }
    }
}