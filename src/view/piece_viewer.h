#ifndef KAMISADO_PIECE_VIEWER_H
#define KAMISADO_PIECE_VIEWER_H

#include <SDL2/SDL_image.h>

#include "../model/match/piece.h"
#include "asset_manager.h"

class PieceViewer {
private:
    const AssetManager& assetManager_;
public:
    PieceViewer(const AssetManager& assetManager);
    void draw(const Piece&, const SDL_Rect&) const;
};

#endif //KAMISADO_PIECE_VIEWER_H
