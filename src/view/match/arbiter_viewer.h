#ifndef KAMISADO_ARBITER_VIEWER_H
#define KAMISADO_ARBITER_VIEWER_H

#include "asset_manager.h"
#include "../../control/match/arbiter.h"
#include "board_viewer.h"
#include "piece_viewer.h"
#include "square_filler.h"

class ArbiterViewer {
private:
    const Arbiter& arbiter_;
    const AssetManager& assetManager_;
    const BoardViewer& boardViewer_;
    const PieceViewer& pieceViewer_;
    const SquareFiller& squareFiller_;
    const SDL_Rect& screen_rectangle_;
public:
    ArbiterViewer(const Arbiter&, const AssetManager&, const BoardViewer&, const PieceViewer&, const SquareFiller&, const SDL_Rect&);
    void draw() const;
};

#endif //KAMISADO_ARBITER_VIEWER_H
