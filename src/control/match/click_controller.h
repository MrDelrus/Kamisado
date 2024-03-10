#ifndef KAMISADO_CLICK_CONTROLLER_H
#define KAMISADO_CLICK_CONTROLLER_H

#include "../../model/match/piece.h"

class ClickController {
private:
    int width_;
    int height_;
public:
    ClickController(int, int);

    Position get_position(int, int);

};

#endif //KAMISADO_CLICK_CONTROLLER_H