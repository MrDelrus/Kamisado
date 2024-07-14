#ifndef KAMISADO_PIECEVIEWER_H
#define KAMISADO_PIECEVIEWER_H

#include <SDL2/SDL_image.h>

#include "../../model/match/Piece.h"
#include "AssetManager.h"

class PieceViewer {
private:
    const AssetManager& assetManager_;
    const SDL_Rect board_rectangle_;
public:
    PieceViewer(const AssetManager&, SDL_Rect);
    void draw(const Piece&) const;
};

#endif //KAMISADO_PIECEVIEWER_H
