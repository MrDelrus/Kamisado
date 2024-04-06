#ifndef KAMISADO_ARBITER_VIEWER_H
#define KAMISADO_ARBITER_VIEWER_H

#include "asset_manager.h"
#include "board_viewer.h"
#include "../control/match/board_controller.h"

class ArbiterViewer {
private:
    int width_;
    int height_;
    const AssetManager& assetManager_;
    const BoardViewer& boardViewer_;
    const Board& board_;
public:
    ArbiterViewer(int, int, const AssetManager&, const BoardViewer&, const Board&);
    void draw() const;
};

#endif //KAMISADO_ARBITER_VIEWER_H
