#ifndef KAMISADO_BOARD_VIEWER_H
#define KAMISADO_BOARD_VIEWER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../model/match/board.h"
#include "asset_manager.h"
#include "piece_viewer.h"

class BoardViewer {
private:
    const int width_;
    const int height_;
    const Board& board_;
    const AssetManager& assetManager_;
    const PieceViewer& pieceViewer_;
public:
    BoardViewer(int width, int height, const Board&, const AssetManager&, const PieceViewer&);
    void draw() const;
};

#endif //KAMISADO_BOARD_VIEWER_H
