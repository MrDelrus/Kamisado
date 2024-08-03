#ifndef KAMISADO_BOARDCLICKEVENTHANDLER_H
#define KAMISADO_BOARDCLICKEVENTHANDLER_H

#include <iostream>
#include <SDL_rect.h>
#include "../events/SceneryEvent.h"
#include "../../model/match/Piece.h"

class BoardClickEventHandler {
private:
    const SDL_Rect board_rectangle_;
public:
    Position handle(SceneryEvent);
};

#endif //KAMISADO_BOARDCLICKEVENTHANDLER_H
