#ifndef KAMISADO_ARBITER_VIEWER_H
#define KAMISADO_ARBITER_VIEWER_H

#include "asset_manager.h"
#include "../../control/match/board_controller.h"
#include "board_viewer.h"
#include "piece_viewer.h"
#include "square_filler.h"

class ArbiterViewer {
private:
    const Board& board_;
    const AssetManager& assetManager_;
    const BoardViewer& boardViewer_;
    const PieceViewer& pieceViewer_;
    const SquareFiller& squareFiller_;
    const SDL_Rect& screen_rectangle_;
public:
    ArbiterViewer(const Board&, const AssetManager&, const BoardViewer&, const PieceViewer&, const SquareFiller&, const SDL_Rect&);
    void draw(const std::vector<Position>&, Position = {-1, -1}, Position = {-1, -1}) const;
};

#endif //KAMISADO_ARBITER_VIEWER_H
