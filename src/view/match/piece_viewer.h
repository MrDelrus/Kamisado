#ifndef KAMISADO_PIECE_VIEWER_H
#define KAMISADO_PIECE_VIEWER_H

#include <SDL2/SDL_image.h>

#include "../../model/match/piece.h"
#include "asset_manager.h"

class PieceViewer {
private:
    const AssetManager& assetManager_;
    const SDL_Rect board_rectangle_;
public:
    PieceViewer(const AssetManager&, SDL_Rect);
    void draw(const Piece&) const;
};

#endif //KAMISADO_PIECE_VIEWER_H
