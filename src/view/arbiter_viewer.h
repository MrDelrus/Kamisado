#ifndef KAMISADO_ARBITER_VIEWER_H
#define KAMISADO_ARBITER_VIEWER_H

#include "asset_manager.h"
#include "board_viewer.h"
#include "../control/match/board_controller.h"

class ArbiterViewer {
private:
    int width_;
    int height_;
    AssetManager assetManager_;
    BoardViewer boardViewer_;
    Board& board_;
public:
    ArbiterViewer(int, int, SDL_Renderer*, Board&);
    void draw() const;
};

#endif //KAMISADO_ARBITER_VIEWER_H
