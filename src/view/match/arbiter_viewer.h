#ifndef KAMISADO_ARBITER_VIEWER_H
#define KAMISADO_ARBITER_VIEWER_H

#include "asset_manager.h"
#include "../../model/match/board.h"
#include "board_viewer.h"
#include "piece_viewer.h"

class ArbiterViewer {
private:
    const Board& board_;
    const AssetManager& assetManager_;
    const BoardViewer& boardViewer_;
    const PieceViewer& pieceViewer_;
    const SDL_Rect& screen_rectangle_;
public:
    ArbiterViewer(const Board&, const AssetManager&, const BoardViewer&, const PieceViewer&, const SDL_Rect&);
    void draw() const;
};

#endif //KAMISADO_ARBITER_VIEWER_H
