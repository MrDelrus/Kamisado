#ifndef KAMISADO_ARBITER_VIEWER_H
#define KAMISADO_ARBITER_VIEWER_H

#include "asset_manager.h"
#include "board_viewer.h"

class ArbiterViewer {
private:
    int width_;
    int height_;
    AssetManager assetManager_;
    BoardViewer boardViewer_;
public:
    ArbiterViewer(int, int, SDL_Renderer*);
    void draw(const Board&) const;
};

#endif //KAMISADO_ARBITER_VIEWER_H
