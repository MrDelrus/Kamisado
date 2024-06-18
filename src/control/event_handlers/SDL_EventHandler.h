#ifndef KAMISADO_SDL_EVENTHANDLER_H
#define KAMISADO_SDL_EVENTHANDLER_H

#include "AppLifeCycleEventHandler.h"
#include "../event_transmitters/SceneryEventTransmitter.h"
#include <SDL.h>

class SDL_EventHandler {
private:
   AppLifeCycleEventHandler& appLifeCycleEventHandler_;
   SceneryEventTransmitter& sceneryEventTransmitter_;
public:
    SDL_EventHandler(AppLifeCycleEventHandler&, SceneryEventTransmitter&);
    void update();
};

#endif //KAMISADO_SDL_EVENTHANDLER_H
