#ifndef KAMISADO_ARBITERVIEWER_H
#define KAMISADO_ARBITERVIEWER_H

#include "AssetManager.h"
#include "../../control/match/Arbiter.h"
#include "BoardViewer.h"
#include "PieceViewer.h"
#include "SquareFiller.h"

class ArbiterViewer {
private:
    const Board& board_;
    const AssetManager& assetManager_;
    const BoardViewer& boardViewer_;
    const PieceViewer& pieceViewer_;
    const SquareFiller& squareFiller_;
    const SDL_Rect screen_rectangle_;
public:
    ArbiterViewer(const Board&, const AssetManager&, const BoardViewer&, const PieceViewer&, const SquareFiller&, SDL_Rect);
    void draw() const;
};

#endif //KAMISADO_ARBITERVIEWER_H
