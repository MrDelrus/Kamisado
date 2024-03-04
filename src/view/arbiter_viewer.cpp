#include "arbiter_viewer.h"

ArbiterViewer::ArbiterViewer(int width, int height, SDL_Renderer* renderer, const Board& board) :
        width_(width), height_(height), assetManager_(renderer), board_(board) {}

void ArbiterViewer::draw() const {

    SDL_RenderClear(assetManager_.get_renderer());

    boardViewer_.draw(board_, assetManager_, width_, height_);

    SDL_RenderPresent(assetManager_.get_renderer());
}
