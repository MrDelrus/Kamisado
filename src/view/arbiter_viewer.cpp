#include "arbiter_viewer.h"

ArbiterViewer::ArbiterViewer(int width, int height, SDL_Renderer* renderer) : width_(width), height_(height),
                                                                              assetManager_(renderer) {}

void ArbiterViewer::draw(const Board& board) const {
    SDL_RenderClear(assetManager_.get_renderer());

    boardViewer_.draw(board, assetManager_, width_, height_);

    SDL_RenderPresent(assetManager_.get_renderer());
}
