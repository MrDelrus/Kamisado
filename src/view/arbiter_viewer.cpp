#include "arbiter_viewer.h"

ArbiterViewer::ArbiterViewer(int width, int height, const AssetManager& assetManager, const BoardViewer& boardViewer, const Board& board) :
        width_(width), height_(height), assetManager_(assetManager), boardViewer_(boardViewer), board_(board) {}

void ArbiterViewer::draw() const {

    SDL_RenderClear(assetManager_.get_renderer());

    boardViewer_.draw();

    SDL_RenderPresent(assetManager_.get_renderer());
}
