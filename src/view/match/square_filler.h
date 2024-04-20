#ifndef KAMISADO_SQUARE_FILLER_H
#define KAMISADO_SQUARE_FILLER_H

#include <SDL.h>
#include "../../model/match/piece.h"

class SquareFiller {
private:
    SDL_Renderer* renderer_;
    const SDL_Rect& board_rectangle_;
public:
    SquareFiller(SDL_Renderer*, const SDL_Rect&);
    void draw(Position, int red, int green, int blue, int opacity) const;
};

#endif //KAMISADO_SQUARE_FILLER_H
