#include "SDL_EventHandler.h"
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
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                SceneryEvent sceneryEvent;
                sceneryEvent.is_click = false;
                sceneryEvent.key = SceneryEvent::Key::Escape;
                sceneryEventTransmitter_.handle(sceneryEvent);
            } else if (event.key.keysym.sym == SDLK_RETURN) {
                SceneryEvent sceneryEvent;
                sceneryEvent.is_click = false;
                sceneryEvent.key = SceneryEvent::Key::Enter;
                sceneryEventTransmitter_.handle(sceneryEvent);
            }
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            SceneryEvent sceneryEvent;
            sceneryEvent.x_click = event.button.x;
            sceneryEvent.y_click = event.button.y;
            sceneryEvent.is_click = true;
            sceneryEventTransmitter_.handle(sceneryEvent);
        }
    }
}