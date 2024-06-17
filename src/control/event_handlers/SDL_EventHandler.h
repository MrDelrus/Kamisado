#ifndef KAMISADO_SDL_EVENTHANDLER_H
#define KAMISADO_SDL_EVENTHANDLER_H

#include "AppLifeCycleEventHandler.h"
#include "SceneryEventHandler.h"
#include <SDL.h>

class SDL_EventHandler {
private:
   AppLifeCycleEventHandler& appLifeCycleEventHandler_;
   SceneryEventHandler* sceneryEventHandler_ = nullptr;
public:
    explicit SDL_EventHandler(AppLifeCycleEventHandler&, SceneryEventHandler*);
    void handle();
};

#endif //KAMISADO_SDL_EVENTHANDLER_H
