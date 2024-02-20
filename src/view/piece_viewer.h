#ifndef KAMISADO_PIECE_VIEWER_H
#define KAMISADO_PIECE_VIEWER_H

#include <SDL2/SDL_image.h>

#include "../model/match/piece.h"

class PieceViewer {
public:
    void draw(const Piece&, SDL_Renderer*, SDL_Texture*, const SDL_Rect&) const;
};

#endif //KAMISADO_PIECE_VIEWER_H
